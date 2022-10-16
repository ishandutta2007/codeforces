#include <iostream>
#include <string>

using namespace std;

int frecvs[26];
int frecvt[26];

int main()
{
    string s,t;
    cin>>s>>t;

    for(int i=0;i<s.size();i++)
        frecvs[s[i]-'a']++;

    for(int i=0;i<t.size();i++)
        frecvt[t[i]-'a']++;

    bool ok=true;
    for(int i=0;i<26;i++)
        if(frecvs[i]<frecvt[i]){
            ok=false;
            break;
        }

    if(!ok){
        cout<<"need tree\n";
        return 0;
    }

    //Automaton
    int j=0;

    for(int i=0;i<s.size() && j<t.size();i++)
        if(s[i]==t[j])
            j++;

    if(j==t.size()){
        cout<<"automaton\n";
        return 0;
    }

    //Array
    ok=true;

    for(int i=0;i<26;i++)
    if(frecvs[i]!=frecvt[i]){
        ok=false;
        break;
    }

    if(ok){
        cout<<"array\n";
        return 0;
    }
    cout<<"both\n";

    return 0;
}