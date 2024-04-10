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
#define sec second 
#define int64 long long        
#define ld long double 
 
const int inf=2000000000; 
 
int n;
string s1,s2,s;

int main(){ 
    scanf("%d ",&n);
    bool f1=false;
    bool f2=false;
    int a1=0;
    int a2=0;


    for (int i=0;i<n;++i){
        getline(cin,s);
        if (!f1){
            s1=s;
            f1=true;
            ++a1;
            continue;
        }
        if (s==s1){
            ++a1;
            continue;
        }
        if (!f2){
            s2=s;
            f2=true;
            ++a2;
            continue;
        }
        if (s==s2){
            ++a2;
            continue;
        }
    }
    assert(a1!=a2);
    if (a1>a2)
        cout<<s1;
    else cout<<s2;
    return 0; 
}