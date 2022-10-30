#include <bits/stdc++.h>

using namespace std;

int n, a[200001], b[200001], mini[200001], maxi[200001];

long long megold(int x, int y) {
 //   cout << x << " " <<y << endl;
    if(y<x) return 0;
    if(x==y) return ((a[x]==b[y])?1:0);
    long long ki=0;
    int c=(x+y)/2, je=1000000001, jdb=0, be=1000000002, bdb=0;
    ki+=megold(x,c)+megold(c+1,y);
 //   cout << x << " " <<y << endl;
    mini[c]=b[c];
    maxi[c]=a[c];
    if(mini[c]==maxi[c]) {
        be=mini[c];
        bdb++;
    }
    for(int i=c-1;i>=x;i--) {
        mini[i]=min(mini[i+1],b[i]);
        maxi[i]=max(maxi[i+1],a[i]);
        if(mini[i]==maxi[i]) {
            be=mini[i];
            bdb++;
        }
    }
    mini[c+1]=b[c+1];
    maxi[c+1]=a[c+1];
    if(mini[c+1]==maxi[c+1]) {
        je=mini[c+1];
        jdb++;
    }
    for(int i=c+2;i<=y;i++) {
        mini[i]=min(mini[i-1],b[i]);
        maxi[i]=max(maxi[i-1],a[i]);
        if(mini[i]==maxi[i]) {
            je=mini[i];
            jdb++;
        }
    }
//    cout << je << " " << jdb << " " << be << " " <<bdb << endl;
    while(x<=c && mini[x]<=maxi[x]) x++;
    while(y>=c+1 && mini[y]<=maxi[y]) y--;
    if(je==be) ki+=(long long)jdb*bdb;
    if(jdb>0) for(int i=c; i>=x;i--) {
        if(maxi[i]<=je && mini[i]>=je) ki+=jdb;
    }
    if(bdb>0) for(int i=c+1; i<=y;i++) {
        if(maxi[i]<=be && mini[i]>=be) ki+=bdb;
    }
    int kis=y+1, na=y;
    for(int i=c; i>=x;i--) {
        while(na>=c+1 && maxi[na]>mini[i]) na--;
        while(kis>c+1 && maxi[kis-1]>=mini[i]) kis--;
        if(na>=kis) ki+=na-kis+1;
    }
    kis=y+1; na=y;
    for(int i=c; i>=x;i--) {
        while(na>=c+1 && mini[na]<maxi[i]) na--;
        while(kis>c+1 && mini[kis-1]<=maxi[i]) kis--;
        if(na>=kis) ki+=na-kis+1;
    }
//    cout << "*" << ki << endl;
    return ki;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }
    cout << megold(0,n-1) << endl;
    return 0;
}