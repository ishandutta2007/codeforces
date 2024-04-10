#include <bits/stdc++.h>

using namespace std;

const char O = char(34);

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> lib;
    vector<int> word;
    bool bad = false;
    for(int i = 0; i < n; i++)
        if(s[i]==','||s[i]==';'){
            if(!word.empty()&&!bad&&(word.size()==1||s[word[0]]!='0'))
                lib.push_back(word);
            word.clear();
            bad=false;
        } else {
            word.push_back(i);
            if(s[i]=='.'||isalpha(s[i]))
                bad=true;
        }
    if(!word.empty()&&!bad&&(word.size()==1||s[word[0]]!='0'))
        lib.push_back(word);
    int m = lib.size();
    vector<bool> used(n,false);
    string A;
    for(int i=0; i<m; i++){
        for(int j:lib[i]){
            A+=s[j];
            used[j]=true;
        }
        if(i<m-1)
            A+=',';
    }
    if(A.size()==n)
        return cout<<O<<s<<O<<"\n"<<'-',0;
    if(A.empty())
        cout<<"-\n"<<O;
    else
        cout<<O<<A<<O<<"\n"<<O;
    lib.clear();
    word.clear();
    for(int i=n-2; i>=0; i--)
        if(used[i]&&(s[i+1]==','||s[i+1]==';'))
            used[i+1]=true;
    for(int i=0; i<n; i++)
        if(!used[i]){
            if(s[i]==','||s[i]==';'){
                lib.push_back(word);
                word.clear();
            } else {
                word.push_back(i);
            }
        }
    if(!word.empty()||s[n-1]==','||s[n-1]==';')
        lib.push_back(word);
    m=lib.size();
    for(int i=0; i<m; i++){
        for(int j:lib[i])
            cout<<s[j];
        if(i<m-1)
            cout<<',';
    }
    cout<<O;
}