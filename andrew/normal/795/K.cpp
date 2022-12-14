#include <iostream>

using namespace std;

   char c;
   string s,s1;
   long long fl,n,i,j,a[100001],b[100001],k,o;
int main()
{
    s1="aeiouy";
    cin >> n;
    cin>>s;
    k=1;
    c=s[n-1];
    for(i=n-2; i>=0;i--)
    {
        if(s[i]==c) {k++; continue;}
        fl=0;
        for(j=0;j<7;j++) if(c==s1[j]) {fl=j+1; break;}

        if(fl==0) {k=1; c=s[i]; continue;}
        if((c!='e')and(c!='o'))
        {
            s.erase(i+1,k-1);
            k=1;
            c=s[i];
            continue;
        }
        if(k!=2)
        {
            s.erase(i+1,k-1);
            k=1;
            c=s[i];
            continue;
        }
      k=1;
      c=s[i];
    }
        fl=0;
        for(j=0;j<7;j++) if(c==s1[j]) {fl=j+1; break;}
        if(( (c!='e')and(c!='o')and(fl!=0)) or((fl!=0)and(k!=2)))
        {
            s.erase(1,k-1);
        }
    cout << s << endl;
    return 0;
}