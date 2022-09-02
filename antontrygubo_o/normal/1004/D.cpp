#include<bits/stdc++.h>
using namespace std;

#define ll long long

int counter(int m, int n, int dist)
{
    if (dist<0) return 0;
    if (dist>m+n-2) return 0;
    if (m<n) swap(m, n);
    if (dist<=n-1) return dist+1;
    if (dist<=m-1) return n;
    return m+n-1-dist;
}


int f(int m, int n, int x, int y, int dist)
{
    int result = 0;
    if (dist==0) return 1;
    if (x>dist) result++;
    if (y>dist) result++;
    if (n+1-x>dist) result++;
    if (m+1-y>dist) result++;

    result+=counter(x-1, y-1, dist-2);

    result+=counter(n-x, y-1, dist-2);

    result+=counter(n-x, m-y, dist-2);

    result+=counter(x-1, m-y, dist-2);

    return result;
}

bool check(int m, int n, int x, int y, vector<int> cell, int area)
{
    if (m*n!=area) return false;
    if (x<=0||x>n) return false;
    if (y<=0||y>m) return false;
    for (int i = 0; i<area; i++) if (cell[i]!=f(m, n, x, y, i)) return false;
    return true;
}

int main()
{
int area;
cin>>area;
vector<int> cell(area);
int temp;
int maxdist = 0;
for (int i = 0; i<area; i++) {cin>>temp; cell[temp]++; maxdist = max(maxdist, temp);}


/*if (cell[0]!=1) {cout<<-1; return 0;}
if (cell[maxdist]>4||cell[maxdist]==3) {cout<<-1; return 0;}
if (cell[maxdist]==4)
{
    if (maxdist%2==1) {cout<<-1; return 0;}
    if (check(maxdist+1, maxdist+1, maxdist/2 + 1, maxdist/2 + 1, cell, area)) {cout<<maxdist+1<<' '<<maxdist+1<<endl<<maxdist/2+1<<' '<<maxdist/2+1; return 0;}
    else {cout<<-1; return 0;}
}

if (cell[maxdist==2])
{
    int current = maxdist;
    while (cell[current]==2*(maxdist+1-current)) current--;
    if (cell[current]<2*(maxdist+1-current))
    {
        int t = maxdist-current; 
        int m = 2*t+1;
        if (area%m!=0) {cout<<-1; return 0;}
        int n = area/m;
        if (!check(m, n, t+1, current+1, cell, area)) {cout<<-1; return 0;}
        else
        {
            cout<<n<<' '<<m<<endl<<t+1<<' '<<current+1;
        }
    }
    else if (cell[current]>2*(maxdist+1-current))
    {
        for (int m = 1; m<=area; m+=2)
        if (area%m==0&&m+(area/m) == current+maxdist+2)
        {
            int t = m/2;
            int n = area/m;
            if (check(m, n, maxdist-t+1, t+1, cell, area)) {cout<<n<<' '<<m<<endl<<maxdist-t+1<<' '<<t+1; return 0;}
        }
        
        cout<<-1; return 0;
    }
}

if (cell[maxdist]==1)
{
    
}*/

if (cell[0]!=1) {cout<<-1; return 0;}
if (area==1)
{
    cout<<1<<' '<<1<<endl<<1<<' '<<1;
    return 0;
}

int nearcut = 1;
while (nearcut<area&&cell[nearcut]==nearcut*4) nearcut++;
if (nearcut==area) {cout<<-1; return 0;}

nearcut--;
/*cout<<nearcut<<' '<<maxdist<<endl;
cout<<endl;*/
for (int m = 1; m<=sqrt(area); m++)
{
    if (area%m==0)
    {
        int n = area/m;
        if (check(m, n, nearcut+1,  maxdist-n+nearcut+2, cell, area)) {cout<<n<<' '<<m<<endl<<nearcut+1<<' '<<maxdist-n+nearcut+2; return 0;}
        if (check(n, m, nearcut+1,  maxdist-m+nearcut+2, cell, area)) {cout<<m<<' '<<n<<endl<<nearcut+1<<' '<<maxdist-m+nearcut+2; return 0;}
        
    }
}
cout<<-1;
return 0;


}