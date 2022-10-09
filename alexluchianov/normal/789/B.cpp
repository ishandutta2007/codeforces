#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
//ifstream in ("b.in");
//ofstream out ("b.out");

int v[30];
int main()
{
  long long l ,b ,q ;
  int pointer = 0 ,m ,a;
  cin>>b>>q>>l>>m;
  if(q == 0){
    int b2 = b;
    b *= q;
    bool ok = (fabs(b2) <= l) ,ok2 = (fabs(b2) <= l);

    for(int i = 0 ; i < m ;i++){
      cin>>a;
      if(b == a){
        ok = 0;
      } else if(b2 == a)
        ok2 = 0;
    }
    if(ok == 0 && ok2 == 0)
      cout<<"0";
    else if(ok == 0 && ok2 == 1)
      cout<<"1";
    else
      cout<<"inf";
  } else if(q == 1){

    bool ok = (fabs(b) <= l);
    for(int i = 0 ; i < m ;i++){
      cin>>a;
      if(b == a)
        ok = 0;
    }
    if(ok == 0)
      cout<<"0";
    else
      cout<<"inf";

  } else if(b == 0){
    bool ok = 1;
    for(int i = 0 ; i < m ;i++){
      cin>>a;
      if(b == a)
        ok = 0;
    }
    if(ok == 0)
      cout<<"0";
    else
      cout<<"inf";

  } else if(q == -1){
      b = fabs(b);
      int ok = (b <= l) ,ok2 = (b <= l);
      for(int i = 0 ; i < m ;i++){
        cin>>a;
        if(b * -1 == a){
          ok = 0;

        } else if(b == a){
          ok2 = 0;
        }
      }
      if(ok + ok2 == 0)
        cout<<"0";
      else
        cout<<"inf";

  }else {
    while(fabs(b) <= l){
      v[pointer] = (int)b;
      b *= q;
      pointer++;
      //cout<<b<<" ";
    }
    int s = pointer ,a;
    for(int i = 0 ; i < m ;i++){
      cin>>a;
      if(a != 0){
        for(int j = 0 ; j < pointer ;j++){
          if(v[j] == a){
            s--;
            v[j] = 0;
          }
        }
      }
    }
    cout<<s;
  }
  return 0;
}


/*

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
ifstream in ("b.in");
ofstream out ("b.out");

int v[30];
int main()
{
  long long l ,b ,q ;
  int pointer = 0 ,m ,a;
  in>>b>>q>>l>>m;
  if(q == 0 || q == 1 || b == 0){
    b *= q;
    bool ok = 1;
    for(int i = 0 ; i < m ;i++){
      in>>a;
      if(b == a){
        ok = 0;
        break;
      }
    }
    if(ok == 0)
      out<<"0";
    else
      out<<"inf";
  } else if(q == -1){
    int ok = 1 ,ok2 = 1;
    b = fabs(b);

    for(int i = 0 ; i < m ;i++){
      in>>a;
      if(b * -1 == a){
        ok = 0;

      } else if(b == a){
        ok2 = 0;
      }
    }
    if(ok + ok2 == 0)
      out<<"0";
    else
      out<<"inf";

  }else {
    while(fabs(b) <= l){
      v[pointer] = (int)b;
      b *= q;
      pointer++;
      //cout<<b<<" ";
    }
    int s = pointer ,a;
    for(int i = 0 ; i < m ;i++){
      in>>a;
      for(int j = 0 ; j < pointer ;j++){
        if(v[j] == a){
          s--;

        }
      }
    }
    out<<s;
  }
  return 0;
}

*/