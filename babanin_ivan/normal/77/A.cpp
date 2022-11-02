#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;

int getnum(string s){
    if (s=="Anka")
        return 0;
    if (s=="Chapay")
        return 1;
    if (s=="Cleo")
        return 2;
    if (s=="Troll")
        return 3;
    if (s=="Dracul")
        return 4;
    if (s=="Snowy")
        return 5;
    if (s=="Hexadecimal")
        return 6;
}

int a[50][50];
int x,y,z;
int b[20];

int ans=-1;
int ans2=0;

void sol(){
    int k[5];
    for (int i=0;i<3;++i)
        k[i]=0;

    for (int i=0;i<7;++i)
        ++k[b[i]];
    for (int i=0;i<3;++i)
        if (!k[i])
            return ;
    int tekans=max(int(x/k[0]),max(int(y/k[1]),int(z/k[2])))-min(int(x/k[0]),min(int(y/k[1]),int(z/k[2])));
    int tek=0;
    for (int i=0;i<7;++i)
        for (int j=0;j<7;++j)
            if (b[i]==b[j])
                tek+=a[i][j];
    if (ans==-1 || tekans<ans || (tekans==ans && ans2<tek)){
        ans=tekans;
        ans2=tek;
    }

}

void perebor(int pos){
    if (pos==7){
        sol();
        return ;
    }
    for (int i=0;i<3;++i){
        b[pos]=i;
        perebor(pos+1);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        string s1,s;
        string s2;
        cin>>s1>>s>>s2;
        a[getnum(s1)][getnum(s2)]=1;
    }
    scanf("%d %d %d",&x,&y,&z);
    perebor(0);
    cout<<ans<<" "<<ans2;
    return 0;
}