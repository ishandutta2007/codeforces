#include<iostream>
//#include<cstdlib>
using namespace std;
char a[1000],b[1000];
int main()
{
    
    int i,l,f,j=0;
    cin>>a;
    i=0;
    do {i++;}while(a[i]!='\0');
    l=i;
    for(i=0;i<l;i++)
    {
          f=0;
          if((a[i]=='W'&&a[i+1]=='U'&&a[i+2]=='B')&&(i<l))
          {
              do 
              {
                  i=i+3;
                  f=1;
              }while((a[i]=='W'&&a[i+1]=='U'&&a[i+2]=='B')&&(i<l)) ;
          }
          if(i<l)
          {
              if(f==1)b[j]=' ',j++;
              b[j]=a[i],j++;
          }
    }
    for(i=0;b[i]==' ';i++);
    for(f=i;f<j;f++)cout<<b[f];
    cout<<endl;                          
    //system("pause");
    //return 0;
}