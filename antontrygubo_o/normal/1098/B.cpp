#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

map<char, int> f;
map<int, char> t;
int main()
{
    ios_base::sync_with_stdio(0);
    f['A'] = 0;
    f['G'] = 1;
    f['C'] = 2;
    f['T'] = 3;
    t[0] = 'A';
    t[1] = 'G';
    t[2] = 'C';
    t[3] = 'T';
    int n, m;
    cin>>n>>m;
    char a[n][m];
    for (int i = 0; i<n; i++)
    for (int j = 0; j<m; j++) cin>>a[i][j];
    
    int minn = 1000000;
    
    int b[n][m];
    for (int i = 0; i<n; i++)
    for (int j = 0; j<m; j++) 
    b[i][j] = f[a[i][j]];
    
    for (int i = 0; i<4; i++)
    for (int j = i+1; j<4; j++)
    {
        int res = 0;
        for (int c = 0; c<m; c+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int r = 0; r<n; r+=2) {if (b[r][c]!=i) res1++; if (b[r][c]!=j) res2++;}
            for (int r = 1; r<n; r+=2) {if (b[r][c]!=i) res2++; if (b[r][c]!=j) res1++;}
            res+=min(res1, res2);
        }
        int i1 = 0;
        int j1 = 0;
        while (i1==i||i1==j) i1++;
        while (j1==i||j1==j||j1==i1) j1++;
        
        for (int c = 1; c<m; c+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int r = 0; r<n; r+=2) {if (b[r][c]!=i1) res1++; if (b[r][c]!=j1) res2++;}
            for (int r = 1; r<n; r+=2) {if (b[r][c]!=i1) res2++; if (b[r][c]!=j1) res1++;}
            res+=min(res1, res2);
        }
        minn = min(minn, res);
    }
    
    //end1
    
    for (int i = 0; i<4; i++)
    for (int j = i+1; j<4; j++)
    {
        int res = 0;
        for (int r = 0; r<n; r+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int c = 0; c<m; c+=2) {if (b[r][c]!=i) res1++; if (b[r][c]!=j) res2++;}
            for (int c = 1; c<m; c+=2) {if (b[r][c]!=i) res2++; if (b[r][c]!=j) res1++;}
            res+=min(res1, res2);
        }
        int i1 = 0;
        int j1 = 0;
        while (i1==i||i1==j) i1++;
        while (j1==i||j1==j||j1==i1) j1++;
        
        for (int r = 1; r<n; r+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int c = 0; c<m; c+=2) {if (b[r][c]!=i1) res1++; if (b[r][c]!=j1) res2++;}
            for (int c = 1; c<m; c+=2) {if (b[r][c]!=i1) res2++; if (b[r][c]!=j1) res1++;}
            res+=min(res1, res2);
        }
        minn = min(minn, res);
    }
    
    //end2
    
    for (int i = 0; i<4; i++)
    for (int j = 0; j<4; j++)
    for (int k = 0; k<4; k++)
    for (int l = 0; l<4; l++) if((i+1)*(j+1)*(k+1)*(l+1)==120)
    {
        
        int res = 0;
        for (int r = 0; r<n; r+=2)
        for (int c = 0; c<m; c+=2)
        if (b[r][c]!=i) res++;
        
        for (int r = 1; r<n; r+=2)
        for (int c = 0; c<m; c+=2)
        if (b[r][c]!=j) res++;
        
        for (int r = 0; r<n; r+=2)
        for (int c = 1; c<m; c+=2)
        if (b[r][c]!=k) res++;
        
        for (int r = 1; r<n; r+=2)
        for (int c = 1; c<m; c+=2)
        if (b[r][c]!=l) res++;
        
        minn = min(minn, res);
    }
    
    //end3
    
    /////////////////////////////////////////////////////////////////////////////////////////
    
    for (int i = 0; i<4; i++)
    for (int j = i+1; j<4; j++)
    {
        int res = 0;
        for (int c = 0; c<m; c+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int r = 0; r<n; r+=2) {if (b[r][c]!=i) res1++; if (b[r][c]!=j) res2++;}
            for (int r = 1; r<n; r+=2) {if (b[r][c]!=i) res2++; if (b[r][c]!=j) res1++;}
            res+=min(res1, res2);
        }
        int i1 = 0;
        int j1 = 0;
        while (i1==i||i1==j) i1++;
        while (j1==i||j1==j||j1==i1) j1++;
        
        for (int c = 1; c<m; c+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int r = 0; r<n; r+=2) {if (b[r][c]!=i1) res1++; if (b[r][c]!=j1) res2++;}
            for (int r = 1; r<n; r+=2) {if (b[r][c]!=i1) res2++; if (b[r][c]!=j1) res1++;}
            res+=min(res1, res2);
        }
        
        if (minn != res) continue;
    
        for (int c = 0; c<m; c+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int r = 0; r<n; r+=2) {if (b[r][c]!=i) res1++; if (b[r][c]!=j) res2++;}
            for (int r = 1; r<n; r+=2) {if (b[r][c]!=i) res2++; if (b[r][c]!=j) res1++;}
            if (res1<=res2) 
            {
                for (int r = 0; r<n; r+=2) b[r][c] = i;
                for (int r = 1; r<n; r+=2) b[r][c] = j;
            }
            else
            {
                for (int r = 0; r<n; r+=2) b[r][c] = j;
                for (int r = 1; r<n; r+=2) b[r][c] = i;
            }
        }
        
        
        for (int c = 1; c<m; c+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int r = 0; r<n; r+=2) {if (b[r][c]!=i1) res1++; if (b[r][c]!=j1) res2++;}
            for (int r = 1; r<n; r+=2) {if (b[r][c]!=i1) res2++; if (b[r][c]!=j1) res1++;}
            if (res1<=res2)
            {
                for (int r = 0; r<n; r+=2) b[r][c] = i1;
                for (int r = 1; r<n; r+=2) b[r][c] = j1;
            }
            else
            {
                for (int r = 0; r<n; r+=2) b[r][c] = j1;
                for (int r = 1; r<n; r+=2) b[r][c] = i1;
            }
        }
    
        for (int r = 0; r<n; r++)
        {
            for (int c = 0; c<m; c++) cout<<t[b[r][c]]; 
            cout<<endl;
        }
        return 0;
    }    
        
        //end1
    
    for (int i = 0; i<4; i++)
    for (int j = i+1; j<4; j++)
    {
        int res = 0;
        for (int r = 0; r<n; r+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int c = 0; c<m; c+=2) {if (b[r][c]!=i) res1++; if (b[r][c]!=j) res2++;}
            for (int c = 1; c<m; c+=2) {if (b[r][c]!=i) res2++; if (b[r][c]!=j) res1++;}
            res+=min(res1, res2);
        }
        int i1 = 0;
        int j1 = 0;
        while (i1==i||i1==j) i1++;
        while (j1==i||j1==j||j1==i1) j1++;
        
        for (int r = 1; r<n; r+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int c = 0; c<m; c+=2) {if (b[r][c]!=i1) res1++; if (b[r][c]!=j1) res2++;}
            for (int c = 1; c<m; c+=2) {if (b[r][c]!=i1) res2++; if (b[r][c]!=j1) res1++;}
            res+=min(res1, res2);
        }
        
        if (res!=minn) continue;
        
        for (int r = 0; r<n; r+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int c = 0; c<m; c+=2) {if (b[r][c]!=i) res1++; if (b[r][c]!=j) res2++;}
            for (int c = 1; c<m; c+=2) {if (b[r][c]!=i) res2++; if (b[r][c]!=j) res1++;}
            if (res1<=res2)
            {
                for (int c = 0; c<m; c+=2) b[r][c] = i;
                for (int c = 1; c<m; c+=2) b[r][c] = j;    
            }
            else
            {
                for (int c = 0; c<m; c+=2) b[r][c] = j;
                for (int c = 1; c<m; c+=2) b[r][c] = i;    
            }
        }
        
        for (int r = 1; r<n; r+=2)
        {
            int res1 = 0;
            int res2 = 0;
            for (int c = 0; c<m; c+=2) {if (b[r][c]!=i1) res1++; if (b[r][c]!=j1) res2++;}
            for (int c = 1; c<m; c+=2) {if (b[r][c]!=i1) res2++; if (b[r][c]!=j1) res1++;}
            if (res1<=res2)
            {
                for (int c = 0; c<m; c+=2) b[r][c] = i1;
                for (int c = 1; c<m; c+=2) b[r][c] = j1;    
            }
            else
            {
                for (int c = 0; c<m; c+=2) b[r][c] = j1;
                for (int c = 1; c<m; c+=2) b[r][c] = i1;    
            }
        }
        
        for (int r = 0; r<n; r++)
        {
            for (int c = 0; c<m; c++) cout<<t[b[r][c]]; 
            cout<<endl;
        }
        return 0;        
    }
    
    
    
    ////
    
    for (int i = 0; i<4; i++)
    for (int j = 0; j<4; j++)
    for (int k = 0; k<4; k++)
    for (int l = 0; l<4; l++) if((i+1)*(j+1)*(k+1)*(l+1)==120)
    {
        
        int res = 0;
        for (int r = 0; r<n; r+=2)
        for (int c = 0; c<m; c+=2)
        if (b[r][c]!=i) res++;
        
        for (int r = 1; r<n; r+=2)
        for (int c = 0; c<m; c+=2)
        if (b[r][c]!=j) res++;
        
        for (int r = 0; r<n; r+=2)
        for (int c = 1; c<m; c+=2)
        if (b[r][c]!=k) res++;
        
        for (int r = 1; r<n; r+=2)
        for (int c = 1; c<m; c+=2)
        if (b[r][c]!=l) res++;
        
        if (res!=minn) continue;

        for (int r = 0; r<n; r+=2)
        for (int c = 0; c<m; c+=2)
        b[r][c] = i;
        
        for (int r = 1; r<n; r+=2)
        for (int c = 0; c<m; c+=2)
        b[r][c] = j;
        
        for (int r = 0; r<n; r+=2)
        for (int c = 1; c<m; c+=2)
        b[r][c] = k;
        
        for (int r = 1; r<n; r+=2)
        for (int c = 1; c<m; c+=2)
        b[r][c] = l;
        
        for (int r = 0; r<n; r++)
        {
            for (int c = 0; c<m; c++) cout<<t[b[r][c]]; 
            cout<<endl;
        }
        return 0;
    }
    
}