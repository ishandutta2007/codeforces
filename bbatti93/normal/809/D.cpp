#include<bits/stdc++.h>

using namespace std;

long long INF=1000000009;

//1 2 3 4 5  5  5
//2 4 6 8 10 11 12
//1 2 2 3 4 5  5
//2 4 5 7 9 11 12
//4 - 12
struct pont {
    int elteres;
    long long randert;
    int reszfaban;
    pont *bal, *jobb;
};

pont *FA, *NIL=new pont;
void jforg (pont* &p) {
    pont* q=p->jobb;
    p->jobb=q->bal;
    p->reszfaban=p->bal->reszfaban+p->jobb->reszfaban+1;
    q->bal=p;
    p=q;
    p->reszfaban=p->bal->reszfaban+p->jobb->reszfaban+1;
}

void bforg (pont* &p) {
    pont* q=p->bal;
    p->bal=q->jobb;
    p->reszfaban=p->bal->reszfaban+p->jobb->reszfaban+1;
    q->jobb=p;
    p=q;
    p->reszfaban=p->bal->reszfaban+p->jobb->reszfaban+1;
}

int nagyobb (int ertek, int eddigkisebb, pont* &hol) { //elso, ami nagyobb egyenlo, mint a kezdete
    if (hol==NIL) return 0;

    if (ertek<=hol->elteres+eddigkisebb+hol->bal->reszfaban+1) {
        //cout<<"nagyobb"<<endl;
        int MOST=nagyobb(ertek,eddigkisebb,hol->bal);
        if (MOST==0) return eddigkisebb+hol->bal->reszfaban+1;
        else return MOST;
    }
    if (ertek>hol->elteres+eddigkisebb+hol->bal->reszfaban+1) {
        //cout<<"kisebb"<<endl;
        return nagyobb(ertek,eddigkisebb+hol->bal->reszfaban+1,hol->jobb);
    }
}

int kisebb (int ertek, int eddigkisebb,pont* &hol) { //utolso, ami kisebb, mint a vege

    if (hol==NIL) return 0;
    //if (ertek==3) cout<<"kiesbb: "<<ertek<<" _ "<<hol->elteres<<" "<<eddigkisebb<<"   "<<hol->bal->reszfaban<<endl;

    if (ertek>hol->elteres+eddigkisebb+hol->bal->reszfaban+1) {
        //cout<<"kisebb \n";
        int MOST=kisebb(ertek,eddigkisebb+hol->bal->reszfaban+1,hol->jobb);
        //cout<<"most: "<<MOST<<endl;
        if (MOST==0) return eddigkisebb+hol->bal->reszfaban+1;
        else return MOST;
    }
    if (ertek<=hol->elteres+eddigkisebb+hol->bal->reszfaban+1) {
        //cout<<"nagyobb \n";
        return kisebb(ertek,eddigkisebb,hol->bal);
    }
}


void hozzavesz(int aktert,pont *&hol) {
    if (hol==NIL) {
        hol=new pont;
        hol->reszfaban=1;
        hol->jobb=NIL;
        hol->bal=NIL;
        hol->randert=rand()%INF;
        hol->elteres=aktert;
    }
    else if (hol->elteres>aktert) {
        hol->reszfaban++;
        hozzavesz(aktert,hol->bal);
        if (hol->bal->randert<hol->randert) bforg(hol);
    }
    else {
        hol->reszfaban++;
        hozzavesz(aktert,hol->jobb);
        if (hol->jobb->randert<hol->randert) jforg(hol);
    }
}

void tenylegtorol (pont * &hol) {
    if (hol==NIL) return;
    if (hol->jobb==NIL &&hol->bal==NIL) hol=NIL;
    else {
        if (hol->jobb!=NIL) {
            jforg(hol);
            hol->reszfaban--;
            tenylegtorol(hol->bal);
        }
        else {
            bforg(hol);
            hol->reszfaban--;
            tenylegtorol(hol->jobb);
        }
    }
}


void torol (int k, pont* &hol) {
    if (hol==NIL) return;
    if (k==hol->bal->reszfaban+1) tenylegtorol(hol);
    else if (k<hol->bal->reszfaban+1) {
        torol(k,hol->bal);
        hol->reszfaban--;
    }
    else {
        torol(k-hol->bal->reszfaban-1,hol->jobb);
        hol->reszfaban--;
    }
}
void iv (int kezd, int veg) {
    int x=nagyobb(kezd,0,FA);
    int y=kisebb(veg,0,FA);
    //cout<<"iv: "<<kezd<<" "<<veg<<" "<<x<<" "<<y<<endl;

    if (x==0) {
        if (kezd-FA->reszfaban-1>=0) hozzavesz(kezd-FA->reszfaban-1,FA);
    }
    else {
        hozzavesz(kezd-x,FA);
        if (y==FA->reszfaban-1) { //az osszes kisebb, mint a vege

        }
        else {
            torol(y+2,FA);
        }
    }
    //cout<<FA->elteres<<" "<<FA->jobb->elteres<<endl<<endl;
}


int n;

int main () {
    ios_base::sync_with_stdio(false);
    srand(15126851);
    FA=NIL;
    NIL->randert=INF;
    NIL->jobb=NIL;
    NIL->bal=NIL;
    NIL->reszfaban=0;
    NIL->elteres=0;

    scanf("%d",&n);
    for (int i=1;i<=n; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        iv(a,b);
    }

    //cout<<FA->elteres<<endl;

    cout<<FA->reszfaban<<endl; //3

}