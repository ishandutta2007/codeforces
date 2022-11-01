#include <bits/stdc++.h>
using namespace std;
struct sk {
    int l, r, fr;
};

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, p;
    cin>>n>>m>>p;
    p--;
    char str[n];
    sk a[n];
    for(int i=0; i<n; i++) { a[i].l=i-1; a[i].r=i+1; cin>>str[i]; }
    stack<int> st;
    for(int i=0; i<n; i++)
        if(str[i]=='(')
            st.push(i);
        else
        {
            int left=st.top();
            st.pop();
            a[left].fr=i;
            a[i].fr=left;
        }
    int head=0;
    for(int i=0; i<m; i++)
    {
        char ch;
        cin>>ch;
        if(ch=='L') p=a[p].l;
        if(ch=='R') p=a[p].r;
        if(ch=='D')
        {
            if(a[p].fr<p)
                p=a[p].fr;

            if(p!=head) a[a[p].l].r=a[a[p].fr].r;
            if(a[a[p].fr].r<n) a[a[a[p].fr].r].l=a[p].l;
            if(a[a[p].fr].r==n)
                p=a[p].l;
            else
            {
                if(p==head) head=a[a[p].fr].r;
                p=a[a[p].fr].r;
            }
        }
    }
    for(int i=head; i<n; i=a[i].r)
        cout<<str[i];
    return 0;
}