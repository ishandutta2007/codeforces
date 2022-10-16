#include <iostream>
#include <string>

using namespace std;

struct nod
{
    int din; //Daca are strategie de castig
    int din2; //Daca are strategie de pierdere
    nod* fii[26];

    nod(int a=0,int b=0): din(a),din2(b) {
        for(int i=0;i<26;i++)
            fii[i]=NULL;
    }
}*rad;

string sir;
void ins(nod* unde, int poz)
{
    if(poz==sir.size())
        return;

    if((unde->fii[sir[poz]-'a'])==NULL)
        unde->fii[sir[poz]-'a']=new nod;
    ins(unde->fii[sir[poz]-'a'],poz+1);
}

void calc(nod *unde)
{
    unde->din=0;

    bool exista=false;
    for(int i=0;i<26;i++)
        if((unde->fii[i])!=NULL){
            exista=true;
            calc(unde->fii[i]);
            if(((unde->fii[i])->din)==0)
                unde->din=1;
            if(((unde->fii[i])->din2)==0)
                unde->din2=1;
        }

    if(!exista)
        unde->din2=1;
}

int main()
{
    rad=new nod;
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>sir;
        ins(rad,0);
    }

    calc(rad);
    if((rad->din)==1){
        if((rad->din2)==1){
            cout<<"First\n";
        }
        else{
            if((k%2)==1)
                cout<<"First\n";
            else
                cout<<"Second\n";
        }
    }
    else{
        if((rad->din2)==1){
            cout<<"Second\n";
        }
        else{
            cout<<"Second\n";
        }
    }

    return 0;
}