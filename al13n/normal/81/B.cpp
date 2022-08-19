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
#define SQ(a) ((a)*(a))

char s[1000000];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    vector<string> src;
    gets(s);
    for(int i=0;s[i];++i){
        char c=s[i];
        if(c==',')
            src.pb(",");
        else if(c=='.'){
            if(s[i+1]=='.'&&s[i+2]=='.')
                i+=2;
            else
                exit(123);
            src.pb("...");
        }else if(c==' '){
            string t;
            while(s[i]==' '){
                t+=' ';
                ++i;
            }
            --i;
            //src.pb(t);
        }else{
            string t;
            while(s[i]>='0'&&s[i]<='9'){
                t+=s[i];
                ++i;
            }
            --i;
            if(t.length()==0||t[0]=='0')
                exit(321);
            src.pb(t);
        }
    }

    bool sp=false;
    forv(i,src){
        string t=src[i];
        if(src[i]==","){
            if(i+1<src.size())
                //if(src[i+1][0]==' ')
                //  src[i+1]=" ";
                //else
                    src.insert(src.begin()+i+1," ");
        }else if(src[i]=="..."){
            if(i)
                if(src[i-1][0]==' ')
                    src[i-1]=" ";
                else
                    src.insert(src.begin()+i," "),++i;
        }else if(i+1<src.size()&&src[i][0]>='0'&&src[i][0]<='9'&&src[i+1][0]>='0'&&src[i+1][0]<='9')
            src.insert(src.begin()+i+1," ");
    }
    forv(i,src)
        cout<<src[i];

    return 0;
}