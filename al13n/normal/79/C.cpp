#pragma comment (linker, "/STACK:90000000")
#include <string>
#include <memory.h>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <utility>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forv(i, v) for (int i = 0; i < (int)(v.size()); ++i)
#define fors(i, s) for (int i = 0; i < (int)(s.length()); ++i)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-9
#define iinf 1000000000

char src[110000];
vector<lng> bad;
const lng B=26+26+10+1+1;

int val(char c){
    if(c>='A'&&c<='Z')
        return c-'A'+1;
    if(c>='a'&&c<='z')
        return c-'a'+26+1;
    if(c>='0'&&c<='9')
        return c-'0'+26+26+1;
    if(c=='_')
        return 26+26+10+1;
    exit(123);
}

char tmp[100];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    gets(src);
    int n;
    cin>>n;
    gets(tmp);
    forn(i,n){
        gets(tmp);
        lng v=0;
        lng t=1;
        for(int i=0;tmp[i];++i){
            v+=t*val(tmp[i]);
            t*=B;
        }
        bad.pb(v);
    }
    sort(all(bad));

    int res=0;
    int resp=0;
    int rb=0;
    for(int i=0;src[i];++i){
        lng v=0;
        for(int j=i;j>=0&&j>=i-9;--j){
            v=v*B+val(src[j]);
            vector<lng>::iterator it=lower_bound(all(bad),v);
            if(it==bad.end()||*it!=v)
                continue;
            rb=max(rb,j+1);
        }
        if(i+1-rb>res){
            res=i+1-rb;
            resp=rb;
        }
    }
    cout<<res<<' '<<resp;

    return 0;
}