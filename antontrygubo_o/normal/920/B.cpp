#include<bits/stdc++.h>
using namespace std;

struct student
{
    int l;
    int r;
    int idx;
};

bool sortstudent(student a, student b)
{
    if (a.l==b.l) return a.idx<b.idx;
    return (a.l<b.l);
}

int main()
{
int t;
cin>>t;
for (int h = 0; h<t; h++)
{
    int n;
    cin>>n;
    student a[n];
    for (int i = 0; i<n; i++) {cin>>a[i].l>>a[i].r; a[i].idx = i;} 
    sort (a, a+n, sortstudent);
    int when[n];
    int timer = 1;
    for (int i = 0; i<n; i++)
    {
        if (a[i].r<timer) when[a[i].idx] = 0;
        else
        {
            if (a[i].l>timer) timer = a[i].l;
            when[a[i].idx] = timer;
            timer++;
        }
    }
    for (int i = 0; i<n; i++) cout<<when[i]<<' ';
    cout<<endl;
    
}
 
}