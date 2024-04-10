#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll facs[20];

void fillfacs()
{
    facs[0] = 1;
    for (int i = 1; i<=19; i++) facs[i]=facs[i-1]*i;
}

ll res(int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9)
{
    return facs[i0+i1+i2+i3+i4+i5+i6+i7+i8+i9]/(facs[i0]*facs[i1]*facs[i2]*facs[i3]*facs[i4]*facs[i5]*facs[i6]*facs[i7]*facs[i8]*facs[i9]);
}

ll result(int a[], bool t)
{
    int b[10] ={};
    for (int i = 0; i<10; i++) {if (a[i]>0) {a[i]--; b[i]++;}}
    if (t&&b[0]==1) {b[0]=0; a[0]++;} 
    ll answer = 0;
    for (int i0 = 0; i0<=a[0]; i0++)
    for (int i1 = 0; i1<=a[1]; i1++)
    for (int i2 = 0; i2<=a[2]; i2++)
    for (int i3 = 0; i3<=a[3]; i3++)
    for (int i4 = 0; i4<=a[4]; i4++)
    for (int i5 = 0; i5<=a[5]; i5++)
    for (int i6 = 0; i6<=a[6]; i6++)
    for (int i7 = 0; i7<=a[7]; i7++)
    for (int i8 = 0; i8<=a[8]; i8++)
    for (int i9 = 0; i9<=a[9]; i9++)
    answer += res(b[0]+i0, b[1]+i1, b[2]+i2, b[3]+i3, b[4]+i4, b[5]+i5, b[6]+i6, b[7]+i7, b[8]+i8, b[9]+i9);
    return answer;
}



int main()
{
    fillfacs();
    int a[10] = {};
    string s;
    cin>>s;
    for (int i = 0; i<s.length(); i++)
    {
        a[s[i]-'0']++;
    }

    
    int a1[10];
    for (int i = 0; i<10; i++) a1[i]=a[i];
    ll Here = result(a, 0);
    
    if (a1[0]>0)
    {
        a1[0]--;
        Here-=result(a1, 1);
    }
    cout<<Here;
    
}