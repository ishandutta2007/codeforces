#include <bits/stdc++.h>

using namespace std;
string Aprepare(string s){
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(int i=0;i<s.length();i++) if(s[i]=='o') s[i]='0'; else if(s[i]=='l') s[i]='1'; else if(s[i]=='i') s[i]='1';
    return s;
}
void A(){
    string s;
    cin >> s;
    s = Aprepare(s);
    int n;
    cin >> n;
    map<string, int> mmap;
    for(int i=0;i<n;i++){
        string k;
        cin >> k;
        mmap[Aprepare(k)]++;
    }
    if(!mmap[s]) cout << "Yes";
    else cout << "No";
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    A();
}