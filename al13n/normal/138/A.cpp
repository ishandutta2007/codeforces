#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-8
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex

bool syll[256];

void nope(){
    cout<<"NO";
    exit(0);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    syll['a']=syll['e']=syll['i']=syll['o']=syll['u']=true;
    int n,k;
    cin>>n>>k;
    set<string> res;
    forn(i,n){
        string suf[4];
        forn(j,4){
            string s;
            cin>>s;
            int p=s.length();
            int c=0;
            while(p>0&&c<k){
                --p;
                if(syll[s[p]])
                    ++c;
            }
            if(c<k)
                nope();
            suf[j]=s.substr(p);
        }
        if(suf[0]==suf[1]){
            if(suf[2]==suf[3]){
                if(suf[1]==suf[2])
                    res.insert("aaaa");
                else
                    res.insert("aabb");
            }else nope();
        }else if(suf[0]==suf[2]){
            if(suf[1]==suf[3])
                res.insert("abab");
            else
                nope();
        }else if(suf[0]==suf[3]&&suf[1]==suf[2])
            res.insert("abba");
        else
            nope();
    }
    if(res.size()>1){
        if(res.size()==2&&*res.begin()=="aaaa"){
            res.erase(res.begin());
        }else nope();
    }
    if(res.size()<1)
        exit(321);
    cout<<*res.begin();

    return 0;
}