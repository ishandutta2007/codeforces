#pragma comment(linker, "/STACK:36777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

string s[1111];
int x[1111];
bool u[1111];
int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    int n;
    cin>>n;
    REP(i,n){
        cin>>s[i]>>x[i];
    }
    int best = -1;int when=0;
    string res;
    REP(i,n)if(!u[i]){
        int score=0,cwhen = n;
        FOR(j,i,n)if(s[j]==s[i]){
            score+=x[j];
            u[j]=true;
        }
        int tt=0;
        FOR(j,i,n)if(s[j]==s[i]){
            tt+=x[j];
            if(tt>=score){
                cwhen=j;
                break;
            }
        }


        if(score>best || score==best && when>cwhen){
             best=score;
            when=cwhen;
            res=s[i];
        }
    }

    cout<<res<<endl;

    return 0;
}