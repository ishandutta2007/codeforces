#include <bits/stdc++.h>

using namespace std;

main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int win=0;

    int a,b,c,d,e,f,g,h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;

    if(a>f && d>g && a>h && d>e)
        win=-1;
    if(c>f && b>g && c>h && b>e)
        win=-1;

    if(a<f && d<g && c<f && b<g)
        win=1;
    if(a<h && d<e && c<h && b<e)
        win=1;

    if(a<f && d<g && c<h && b<e)
        win=1;
    if(a<h && d<e && c<f && b<g)
        win=1;

    if(win==-1)
        cout<<"Team 1"<<endl;
    else if(win==0)
        cout<<"Draw"<<endl;
    else
        cout<<"Team 2"<<endl;
}