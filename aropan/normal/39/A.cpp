#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;
typedef long long huge_t;

const int maxs = 1111;
const int maxn = 10666;

char s[maxn];
int s_m[maxs][maxs];

int A;

struct summand {
  bool pref;
  bool post;
  int coef;
  
  summand() {
    pref = false;
    post = false;
    coef = 1;
  }
};


vector<summand> parse(char *s) {
    vector<summand> r;
    bool fst = true;
    while (*s) {
    
      summand sm;
      int sign;
      
      if (*s == '-') { sign = -1; ++s; }
      else {
        sign = 1;
        if (!fst && *s == '+') s++;
      }
      
      sm.coef = 0;
      if (*s >= '0' && *s <= '9')
      {
          while ((*s >= '0') && (*s <= '9')) {
            sm.coef = sm.coef * 10 + *s++ - '0';
          }
      }
      else
      {
        sm.coef = 1;
      }
      
      
      if (*s == '*') ++s;
      if (*s == '+') sm.pref = true;
      if (*s == 'a') sm.post = true;
      s += 3;
      
      sm.coef *= sign;
            
      r.push_back(sm);
      fst = false;
    }
    
    return r;
}

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/

    scanf("%d\n", &A);
    scanf("%s", s);
    
    vector<summand> sms = parse(s);
    vector<int> pref, post;
    for (vector<summand>::iterator i = sms.begin(); i != sms.end(); ++i) {
      if (i->pref) pref.push_back(i->coef);
      else post.push_back(i->coef);
      //printf("%d %d %d\n", i->coef, i->pref, i->post); 
    }
    
    sort(pref.begin(), pref.end());
    sort(post.begin(), post.end());
    int n1 = pref.size();
    int n2 = post.size();
    
    s_m[0][0] = 0;
    
    for (int i = 1; i <= n1; ++i) {
       int a = A + i;
       s_m[i][0] = s_m[i - 1][0] + pref[i - 1] * a;
    }
    
    for (int j = 1; j <= n2; ++j) {
       int a = A + j - 1;
       s_m[0][j] = s_m[0][j - 1] + post[j - 1] * a;
    }
    
    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        int a = A + i + j;
        int s1 = s_m[i - 1][j] + pref[i - 1] * a;
        int s2 = s_m[i][j - 1] + post[j - 1] * (a - 1);
        s_m[i][j] = max(s1, s2);
      }
    }
    
    printf("%d\n", s_m[n1][n2]);
    
    return 0;
}