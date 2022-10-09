#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 3000;

string v[5 + nmax];
string target[5 + nmax];

int firstdif[5 + nmax];

void computefirst(int n){
  for(int i = 1 ; i <= n ; i++) {
    firstdif[i] = -1;
    for(int h = 0 ; h < v[i].size() ; h++) {
      if(v[i][h] != target[i][h]) {
        firstdif[i] = h;
        break;
      }
    }

  }
}

string change , change2;

void verify(int st){
  int pos = v[st].find(change);
  if(pos < v[st].size()){
    for(int h = pos ; h < pos + change.size() ; h++)
      v[st][h] = change2[h - pos];
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();

  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  for(int i = 1 ; i <= n ; i++)
    cin >> target[i];
  computefirst(n);

  for(int sz = 1 ; sz <= nmax ; sz++){
    char ch = '$';
    char ch2 = '$';
    bool flag = 0;

    for(int i = 1 ; i <= n ; i++){
      if(firstdif[i] != -1){
        if(sz + firstdif[i] - 1 < v[i].size()){
          if(v[i][sz + firstdif[i] - 1] == ch && target[i][sz + firstdif[i] - 1] == ch2 )
            continue;
          else if(ch == '$') {
            ch = v[i][sz + firstdif[i] - 1];
            ch2 = target[i][sz + firstdif[i] - 1];
          } else {
            flag = 1;
            break;
          }
        } else  {
          flag = 1;
          break;
        }
      }
    }
    if(flag == 1)
      break;

    change += ch;
    change2 += ch2;
  }

  for(int sz = 1 ; sz <= nmax ; sz++){
    char ch = '$';
    char ch2 = '$';
    bool flag = 0;

    for(int i = 1 ; i <= n ; i++){
      if(firstdif[i] != -1){
        if(0 <= firstdif[i] - sz){
          if(v[i][firstdif[i] - sz] == ch && target[i][firstdif[i] - sz] == ch2 )
            continue;
          else if(ch == '$') {
            ch = v[i][firstdif[i] - sz];
            ch2 = target[i][firstdif[i] - sz];
          } else {
            flag = 1;
            break;
          }
        } else  {
          flag = 1;
          break;
        }
      }
    }
    if(flag == 1)
      break;

    change = ch + change;
    change2 = ch2 + change2;
  }


  for(int i = 1 ; i <= n ; i++){
    verify(i);
    if(v[i] != target[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << '\n';
  cout << change << '\n';
  cout << change2 << '\n';

  return 0;
}