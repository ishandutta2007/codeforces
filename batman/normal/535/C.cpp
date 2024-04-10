// in the name of allah

#include<bits\stdc++.h>
#include <stdio.h>

#define debug(x) cout#x" = "xendl
#define pb(k) push_back(k)
#define pf(k) push_front(k)
#define pob() pop_back()
#define pof() pop_front()
#define LL long long
#define LB long double
#define PII pair <int,int>
#define PLI pair <long long,int>
#define sin(k) sin(k*PI/180)
#define tan(k) sin(k*PI/180)
#define cot(k) sin(k*PI/180)
#define cos(k) cos(k*PI/180)


using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");

const int MOD=1000*1000*1000+7;
const int MAXN=100*100*100+100;
const int INF=1000*1000*1000+9;

long long lf,t,m,a,b;

bool check(int rg){
 if((a*(rg-lf+1))+(b*(rg-lf+1)*(lf+rg-2)/2)<=m*t && a+(rg-1)*b<=t)return true;
 else return false;
}

int main(){
 
 ios_base::sync_with_stdio(false);
 cin.tie(false);cout.tie(false);
 
 int n;
 cin>>a>>b>>n;
 while(n--){
 cin>>lf>>t>>m;
 long long MIN=lf-1,MAX=1001*1000;
 while(MAX-MIN>1){
 long long MID=(MAX+MIN)/2;
 if(!check(MID)) MAX=MID; else MIN=MID;
 }
 if(MIN==lf-1)cout<<-1<<'\n';
 else cout<<MIN<<'\n';
 }
}