#include<bits/stdc++.h>
using namespace std;
const int N=100005;
bool tab[2][N];
int main(){
    int n, q;
    cin>>n>>q;
    int blok=0, przek=0;
    while(q--){
        int x, y;
        cin>>x>>y;
        x=x%2;
        if(!tab[x][y] and tab[(x+1)%2][y]) blok++;
        if(tab[x][y]&&tab[(x+1)%2][y]) blok--;
        if(tab[x^1][y+1] and !tab[x][y]) przek++;
        if(tab[x^1][y+1] and tab[x][y]) przek--;
        if(tab[x^1][y-1] and !tab[x][y]) przek++;
        if(tab[x^1][y-1] and tab[x][y]) przek--;
        tab[x][y]^=1;
        if(!blok and !przek)    cout<<"yes\n";
        else    cout<<"no\n";
    }
}