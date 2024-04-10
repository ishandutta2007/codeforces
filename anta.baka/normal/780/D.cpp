#include <bits/stdc++.h>

using namespace std;

string s1[1000], s2[1000];
int n;
int tok[1000];
set<string> w;

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0;i <n;i++) {
        string s,t;
        cin>>s>>t;
        s1[i]=s.substr(0,3);
        s2[i]=s.substr(0,2)+t.substr(0,1);
        tok[i]=-1;
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(s1[i]==s1[j]){
                if(tok[i]==-1){
                    if(w.find(s2[i])!=w.end()){cout<<"NO";return 0;}
                    tok[i]=1;
                    w.insert(s2[i]);
                }
                if(tok[j]==-1){
                    if(w.find(s2[j])!=w.end()){cout<<"NO";return 0;}
                    tok[j]=1;
                    w.insert(s2[j]);
                }
            }
    for(int t=0; t<n; t++)
        for(int i=0; i<n; i++)
            if(tok[i]==-1&&w.find(s1[i])!=w.end()){
                if(w.find(s2[i])!=w.end()){cout<<"NO";return 0;}
                tok[i]=1;
                w.insert(s2[i]);
            }
    cout<<"YES\n";
    for(int i=0; i<n; i++)
        if(tok[i]==-1)cout<<s1[i]<<"\n";
        else cout<<s2[i]<<"\n";
}