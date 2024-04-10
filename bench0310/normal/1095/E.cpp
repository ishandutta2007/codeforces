#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    int l[n],r[n];
    if(s[0]=='(') l[0]=1;
    else l[0]=-1;
    for(int i=1;i<n;i++)
    {
        if(l[i-1]==-1) l[i]=-1;
        else
        {
            if(s[i]=='(') l[i]=l[i-1]+1;
            else l[i]=l[i-1]-1;
        }
    }
    if(s[n-1]==')') r[n-1]=-1;
    else r[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        if(r[i+1]==1) r[i]=1;
        else
        {
            if(s[i]==')') r[i]=r[i+1]-1;
            else r[i]=r[i+1]+1;
        }
    }
    /*for(int i=0;i<n;i++) cout << l[i] << " ";
    cout << endl;
    for(int i=0;i<n;i++) cout << r[i] << " ";
    cout << endl;*/
    int cnt=0;
    if(s[0]==')'&&r[1]==-1) cnt++;
    if(s[n-1]=='('&&l[n-2]==1) cnt++;
    for(int i=1;i<n-1;i++)
    {
        if(l[i-1]==-1) continue;
        if(r[i+1]==1) continue;
        if(s[i]=='(')
        {
            if((l[i-1]-1+r[i+1])==0) cnt++;
        }
        else
        {
            if((l[i-1]+1+r[i+1])==0) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}