#include <bits/stdc++.h>
using namespace std;

int xa, ya, xb, yb, xc, yc, xtg, ytg;

typedef pair <int, int> ii;

bool cmp(ii a, ii b){
    return abs(xc-a.first)+abs(yc-a.second) < abs(xc-b.first)+abs(yc-b.second);
}

ii po[5];

void chaytheox(int x, int a, int b){
    if (a<b){
        for (int i=a+1; i<b; i++){
            cout << x << " " << i << endl;
        }
    } else {
        for (int i=b+1; i<a; i++){
            cout << x << " " << i << endl;
        }
    }
}

void chaytheoy(int y, int a, int b){
    if (a<b){
        for (int i=a+1; i<b; i++){
            cout << i << " " << y << endl;
        }
    } else {
        for (int i=b+1; i<a; i++){
            cout << i << " " << y << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if (abs(xb-xa)+abs(yb-ya) > abs(xc-xa)+abs(yc-ya)){
        xtg=xb;
        ytg=yb;
        xb=xc;
        yb=yc;
        xc=xtg;
        yc=ytg;
    }
    if ((xc-xb)*(xc-xa)<=0){
        if (abs(yc-ya) > abs(yc-yb)){
            //cout << 1 << endl;
            cout << abs(xb-xa)+abs(yb-ya)+abs(yc-yb)+1 << endl;
            cout << xa << " " << ya << endl;
            chaytheox(xa, ya, yb);
            if (xa!=xb && yb!=ya) cout << xa << " " << yb << endl;
            chaytheoy(yb, xa, xb);
            cout << xb << " " << yb << endl;
            chaytheox(xc, yb, yc);
            cout << xc << " " << yc << endl;
            return 0;
        } else {
            //cout << 2 << endl;
            cout << abs(xb-xa)+abs(yb-ya)+abs(yc-ya)+1 << endl;
            cout << xa << " " << ya << endl;
            chaytheoy(ya, xa, xb);
            if (xb!=xa && ya!=yb) cout << xb << " " << ya << endl;
            chaytheox(xb, ya, yb);
            cout << xb << " " << yb << endl;
            chaytheox(xc, ya, yc);
            cout << xc << " " << yc;
            return 0;
        }
    }
    if ((yc-yb)*(yc-ya)<=0){
        if (abs(xc-xa) > abs(xc-xb)){
            //cout << 3 << endl;
            cout << abs(xb-xa)+abs(yb-ya)+1+abs(xc-xb) << endl;
            cout << xa << " " << ya << endl;
            chaytheoy(ya, xa, xb);
            if (xb!=xa && ya!=yb) cout << xb << " " << ya << endl;
            chaytheox(xb, ya, yb);
            cout << xb << " " << yb << endl;
            chaytheoy(yc, xb, xc);
            cout << xc << " " << yc << endl;
            return 0;
        } else {
            //cout << 4 << endl;
            cout << abs(xb-xa)+abs(yb-ya)+abs(xc-xa)+1 << endl;
            cout << xa << " " << ya << endl;
            chaytheox(xa, ya, yb);
            if (xa!=xb && ya!=yb) cout << xa << " " << yb << endl;
            chaytheoy(yb, xa, xb);
            cout << xb << " " << yb << endl;
            chaytheoy(yc, xa, xc);
            cout << xc << " " << yc << endl;
            return 0;
        }
    }
    po[0]=make_pair(xa, ya);
    po[1]=make_pair(xa, yb);
    po[2]=make_pair(xb, ya);
    po[3]=make_pair(xb, yb);
    sort(po, po+4, cmp);
    int u=po[0].first, v=po[0].second;
    if (u==xa && v==ya){
        //cout << 5 << endl;
        cout << abs(xa-xb)+abs(ya-yb)+abs(xa-xc)+abs(ya-yc)+1 << endl;
        cout << xa << " " << ya << endl;
        chaytheoy(ya, xa, xb);
        if (xa!=xb && ya!=yb) cout << xb << " " << ya << endl;
        chaytheox(xb, ya, yb);
        cout << xb << " " << yb << endl;
        chaytheox(xa, ya, yc);
        if (xa!=xc && ya!=yc) cout << xa << " " << yc << endl;
        chaytheoy(yc, xa, xc);
        cout << xc << " " << yc << endl;
        return 0;
    }
    if (u==xb && v==yb){
        //cout << 6 << endl;
        cout << abs(xa-xb)+abs(ya-yb)+abs(xb-xc)+abs(yb-yc)+1 << endl;
        cout << xa << " " << ya << endl;
        chaytheoy(ya, xa, xb);
        if (xa!=xb && ya!=yb) cout << xb << " " << ya << endl;
        chaytheox(xb, ya, yb);
        cout << xb << " " << yb << endl;
        chaytheox(xb, yb, yc);
        if (xb!=xc && yb!=yc) cout << xb << " " << yc << endl;
        chaytheoy(yc, xb, xc);
        cout << xc << " " << yc << endl;
        return 0;
    }
    if (u==xa && v==yb){
        //cout << 7 << endl;
        cout << abs(xa-xb)+abs(ya-yb)+abs(xa-xc)+abs(yb-yc)+1 << endl;
        cout << xa << " " << ya << endl;
        chaytheox(xa, ya, yb);
        if (xa!=xb && ya!=yb) cout << xa << " " << yb << endl;
        chaytheoy(yb, xa, xb);
        cout << xb << " " << yb << endl;
        chaytheox(xa, yb, yc);
        if (xa!=xc && yb!=yc) cout << xa << " " << yc << endl;
        chaytheoy(yc, xa, xc);
        cout << xc << " " << yc << endl;
        return 0;
    }
    if (u==xb && v==ya){
        //cout << 8 << endl;
        cout << abs(xa-xb)+abs(ya-yb)+abs(xb-xc)+abs(ya-yc)+1 << endl;
        cout << xa << " " << ya << endl;
        chaytheoy(ya, xa, xb);
        if (xa!=xb && ya!=yb) cout << xb << " " << ya << endl;
        chaytheox(xb, ya, yb);
        cout << xb << " " << yb << endl;
        chaytheox(xb, ya, yc);
        if (xb!=xc && ya!=yc) cout << xb << " " << yc << endl;
        chaytheoy(yc, xb, xc);
        cout << xc << " " << yc << endl;
        return 0;
    }
}