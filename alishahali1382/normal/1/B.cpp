#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

string s,tmp;

int typ(char ch){
    if ('0'<=ch and ch<='9'){
        return 0;     // number : 0     char : 1
    }
    return 1;
}

string mab1(string s){ //number to letter
    int m=s.size(),e=1,ans=0;
    for (int i=m-1; i>=0; i--){
        ans+=e*(s[i]-'0');
        e*=10;
    }
    stack <char> out;
    int x;
    for (; ans>0; ans=(ans-x+1)/26){
        x=ans%26-1;
        if (x==-1){
            x+=26;
        }
        out.push('A'+x);
        //cout<<x<<endl;
    }
    string t;
    while (!out.empty()){
        t+=out.top();
        out.pop();
    }
    return t;
}

int mab2(string s){ //letter to number
    int m=s.size(),e=1,ans=0;
    for (int i=m-1; i>=0; i--){
        ans+=e*(s[i]-'A'+1);
        e*=26;
    }
    return ans;
}


void solve(string s){
    vector <string> L;
    tmp=s[0];
    int m=s.size();
    for (int i=1; i<m; i++){
        if (typ(s[i])!=typ(s[i-1])){
            L.push_back(tmp);
            tmp=s[i];
        }
        else{
            tmp+=s[i];
        }
    }
    if (tmp!=""){
        L.push_back(tmp);
    }
    int k=L.size();

    /*
    for (int i=0; i<k; i++){
        cout<<L[i]<<endl;
    }*/


    if (k>2){
        cout<<mab1(L[3])<<L[1]<<endl;
        return ;
    }
    cout<<'R'<<L[1]<<'C'<<mab2(L[0])<<endl;
    return ;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>s;
        solve(s);
    }
    //cout<<mab1("494")<<endl;
    return 0;
}