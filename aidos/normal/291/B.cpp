#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () {   
    string s, t = "";
    getline(cin, s);
    int n = s.size(), b = 0, a = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='\"'){
            if(b==0 && a) {
                cout << '<' << t << '>' << endl;
                t = "";
                a = 0;
                b=1;
            }
            else if(b==1){
                cout << '<' << t << '>'<<endl;
                t = "";
                b = 0;
                a = 0;                
            }
            else {
                b = 1;
                a = 0;
                t = "";
            }
        }
        else if(s[i]==' '){
            if(a &&  b==0){
                cout << '<' << t << '>' << endl;
                t = "";
                b = 0;       
                a = 0;
            }
            else if(b==1){
                t+=s[i];
                a++;
            }
        }
        else {
            t+=s[i];    
            a++;
        }
    }
    if(b==0 && a){
        cout << '<' << t << '>' << endl;
    }
    return 0;
}