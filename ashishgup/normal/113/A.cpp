#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

string s, str;
vector<string> male={"lios", "etr", "initis"};
vector<string> female={"liala", "etra", "inites"};
map<int, int> gender;
int f[5];

int getgender()
{
    for(auto it:male)
    {   
        int sz=it.size();
        if(str.size()>=sz && str.substr(str.size()-sz)==it)
            return 1;
    }
    return 0;
}

int typeofword()
{
    for(int i=0;i<3;i++)
    {
        int sz=male[i].size();
        if(str.size()>=sz && str.substr(str.size()-sz)==male[i])
            return i;
    }
    for(int i=0;i<3;i++)
    {
        int sz=female[i].size();
        if(str.size()>=sz && str.substr(str.size()-sz)==female[i])
            return i;
    }
    return 3;
}

int32_t main()
{
    IOS;
    getline(cin, s);
    stringstream ss(s);
    vector<int> cur, shouldbe;
    while(ss>>str)
    {
        gender[getgender()]++;
        cur.push_back(typeofword());
        f[cur.back()]++;
    }
    if(cur.size()==1 && f[3]==0)
    {
        cout<<"YES";
        return 0;
    }
    shouldbe=cur;
    sort(shouldbe.begin(), shouldbe.end());
    cerr<<f[1];
    if(shouldbe!=cur || gender.size()>1 || f[1]!=1 || f[3]>0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0; 
}