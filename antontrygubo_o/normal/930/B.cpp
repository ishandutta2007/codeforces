#include<bits/stdc++.h>
using namespace std;

int A[26][26][5000] = {0};

int main()
{
    string s;
    cin>>s;
    int k = s.length();
    for (int i = 0; i<k; i++)
    for (int j = 1; j<k; j++)
    A[int(s[i])-97][int(s[(i+j)%k])-97][j]++;
    int Good[26] = {0};
    for (int i = 0; i<26; i++)
    {
        int good = 0;
        for (int j = 1; j<k; j++)
        {
            int g = 0;
            for (int s = 0; s<26; s++) if (A[i][s][j]==1) g++;
            good = max(good, g);
        }
        Good[i] = good;
    }
    
    double result = 0;
    for (int i = 0; i<26; i++) {result+=Good[i];}
    double kk = k;
    //cout<<result<<' '<<kk<<' '<<endl;
    cout<<setprecision(9)<<result/kk;
}