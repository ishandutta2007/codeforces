
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define forn(i,n) for(int i=0;i<n;++i)


char a[200000];
char b[200000];
char res[200000];
bool ok[200000];
int d[26][26];


int main()
{
 gets(a);
 gets(b);
 int n = strlen(a);
 int m = strlen(b);
 if (n!=m)
 {
  cout << -1;
  return 0;
 }
 int k;
 scanf("%d", &k);
 gets(res);
 forn(i,26)forn(j,26)if(i==j)d[i][j]=0;else d[i][j]=1000000000;
 forn(i,k)
 {
  char c1, c2;
  scanf("%c %c",&c1,&c2);
  int kk;
  scanf("%d", &kk);
  gets(res);
  c1-='a';
  c2-='a';
  d[c1][c2]=min(d[c1][c2], kk);
//  d[c2][c1]=min(d[c2][c1], kk);
 }
 for(int k=0;k<26;++k)
 for(int i=0;i<26;++i)
 for(int j=0;j<26;++j)
    d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
 forn(i,n)ok[i]=false;
 forn(i,n)
 {
  int q = a[i]-'a';
  int w = b[i]-'a';
  forn(j,26)
  {
   if (d[q][j]+d[w][j]<1000000000)
   {
    if (!ok[i] || (d[q][j]+d[w][j] < d[q][res[i]]+d[w][res[i]]))
    {
     ok[i]=true;
     res[i]=j;
    }   
   }
  }
 }
 
 bool qq=true;
 forn(i,n)if(!ok[i])qq=false;
 if (!qq)
 {
  cout << -1;
  return 0;
 }
 int sum=0;
 forn(i,n)sum+= d[a[i]-'a'][res[i]] + d[b[i]-'a'][res[i]];
 printf("%d\n", sum);
 forn(i,n)printf("%c",'a'+res[i]);
 printf("\n");
 
 return 0;
}