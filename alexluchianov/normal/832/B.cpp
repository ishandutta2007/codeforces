#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream in ("c.in");
ofstream out ("c.out");
int good[30];
int const nmax = 100000;
char v[1 + nmax];

int main()
{
  int l = 0;
  int specc = -1;
  char tempg[1 + nmax];
  cin>>tempg;
  int lg = strlen(tempg);
  for(int i = 0 ; i < lg ;i++){
    good[tempg[i] - 'a'] = 1;
  }
  cin>>v;
  l = strlen(v);
  for(int i = 0 ; i < l ;i++){
    if(v[i] == '*'){
      specc = i;
    }
  }
  int t;
  cin>>t;
  for(int i = 0 ; i < t ;i++){
    char temp[1 + nmax];
    cin>>temp;
    int l2 = strlen(temp);
    if(specc == -1){
      if(l != l2){
        cout<<"NO\n";
      } else{
        bool ok = 1;
        for(int i = 0 ; i < l ;i++){
          if(v[i] != '?' && v[i] != temp[i]){
            ok = 0;
            break;
          } else if(v[i] == '?' && good[temp[i] - 'a'] != 1){
            ok = 0;
            break;
          }
        }
        if(ok == 1)
          cout<<"YES\n";
        else
          cout<<"NO\n";
      }
    } else{
      if(l2 + 1 < l){
        cout<<"NO\n";
      } else{
        bool ok = 1;
        int tempp1 = 0;
        if(temp[tempp1] == '*')
          tempp1++;

        for(int i = 0 ; i < specc ;i++){
          if(v[i] != '?' && v[i] != temp[tempp1]){
            ok = 0;
            break;
          } else if(v[i] == '?' && good[temp[tempp1] - 'a'] != 1){
            ok = 0;
            break;
          }
          tempp1++;
        }
        int tempp2;
        tempp2 = l2 - 1;
        if(temp[tempp2] == '*')
          tempp2--;

        for(int i = l - 1; specc < i ;i--){

          if(v[i] != '?' && v[i] != temp[tempp2]){
            ok = 0;
            break;
          } else if(v[i] == '?' && good[temp[tempp2] - 'a'] != 1){
            ok = 0;
            break;
          }
          tempp2--;
        }
        for(int i = specc ;i <= tempp2 ;i++){
          if(good[temp[i] - 'a'] == 1 )
            ok = 0;
        }
        if(ok == 1)
          cout<<"YES\n";
        else
          cout<<"NO\n";

      }
    }
  }

  return 0;
}