// Example program
#include <iostream>
#include <string>

using namespace std;
int main() {
  int a[]={0,0,0,0,0,0,0,0,0,0};
  
  int n;
  cin >> n;
  /*for(int p=0;p<n;p++){
      int b[]={0,0,0,0,0,0,0,0,0,0};
      for (int i=0;i<6;i++){
          int c;
          cin >> c;
          b[c]=1;
      }
      for (int i=0;i<10;i++){
      }
  }*/
  if(n==1){
      int b[]={0,0,0,0,0,0,0,0,0,0};
      for (int i=0;i<6;i++){
          int c;
          cin >> c;
          b[c]=1;
      }
      for (int i=1;i<10;i++){
          if(b[i]==0){
              cout << i-1 << endl;
              return 0;
          }
      }
    }
    if(n==2){
      int b[]={0,0,0,0,0,0,0,0,0,0};
      for (int i=0;i<6;i++){
          int c;
          cin >> c;
          b[c]=1;
      }
      for (int i=0;i<6;i++){
          int c;
          cin >> c;
          a[c]=1;
      }
      for (int i=1;i<10;i++){
          if(b[i]==0&&a[i]==0){
              cout << i-1 << endl;
              return 0;
          }
      }
      for(int i=1;i<10;i++){
          for (int j=0;i<10;i++){
          if((b[i]==0||a[j]==0)&&(b[j]==0||a[i]==0)){
              cout << i*10+j-1 << endl;
              return 0;
          }
      }
      }
    }
    if(n==3){
      int b[]={0,0,0,0,0,0,0,0,0,0};
      int d[]={0,0,0,0,0,0,0,0,0,0};
      for (int i=0;i<6;i++){
          int c;
          cin >> c;
          b[c]=1;
      }
      for (int i=0;i<6;i++){
          int c;
          cin >> c;
          d[c]=1;
      }
      for (int i=0;i<6;i++){
          int c;
          cin >> c;
          a[c]=1;
      }
      for (int i=1;i<10;i++){
          if(b[i]==0&&a[i]==0&&d[i]==0){
              cout << i-1 << endl;
              return 0;
          }
      }
      for(int i=1;i<10;i++){
          for (int j=0;j<10;j++){
          if((b[i]==0||a[j]==0)&&(b[j]==0||a[i]==0)&&(d[i]==0||a[j]==0)&&(d[j]==0||a[i]==0)&&(b[i]==0||d[j]==0)&&(b[j]==0||d[i]==0)){
              cout << i*10+j-1 << endl;
              return 0;
          }
          }
      }
    }
}