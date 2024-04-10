#include <bits/stdc++.h>
using namespace std;

#define puba push_back
vector<char> ans;

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        char ch;
        cin>>ch;
        if(k>0) {
            if(ch-'a'>12)
            {
                if(ch-'a'<=k)
                    ans.puba('a'),k-=ch-'a';
                else
                    ans.puba(char(ch-k)),k=0;
            }
            else
            {
                if('z'-ch<=k)
                    ans.puba('z'),k-='z'-ch;
                else
                    ans.puba(char(ch+k)),k=0;
            }
        } else
            ans.puba(ch);
    }
    if(k!=0)
        cout<<-1;
    else
        for(int i=0; i<n; i++)
            cout<<ans[i];
    return 0;
}