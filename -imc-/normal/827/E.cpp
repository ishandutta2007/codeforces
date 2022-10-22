#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

#define complex complex<double>

inline int nxt() {
    int x;
    cin >> x;
    return x;
}

const double pi = acosl(-1);

const int ANGLES_POWER = 20;
const int ANGLES = 1 << ANGLES_POWER;
complex w[ANGLES];

int rev(int x, int p)
{
    int y = 0;
    for (int i = 0; i < p; i++)
        if (x & (1 << i))
            y |= 1 << (p - 1 - i);
    return y;
}

vector<complex> fft_good(vector<complex> a, int power, bool inverse)
{
    int n = 1 << power;
    
    if (n == 1)
        return a;
    
    vector<complex> even(n / 2), odd(n / 2);
    for (int i = 0; i < n / 2; i++)
    {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }
    
    vector<complex> fft_even = fft_good(even, power - 1, inverse);
    vector<complex> fft_odd  = fft_good(odd, power - 1, inverse);
    
    vector<complex> res(n);
    for (int i = 0; i < n; i++)
    {
        //double phi = 2 * pi * i / (double)(1 << power);
        //if (inverse) phi = -phi;
        
        //complex omega_i(cos(phi), sin(phi));
        
        int index = i << (ANGLES_POWER - power);
        if (inverse)
        {
            index = ANGLES - index;
            if (index == ANGLES) index = 0;
        }
        complex omega_i = w[index];
        
        res[i] = fft_even[i % (n / 2)] + omega_i * fft_odd[i % (n / 2)];
    }
    
    if (inverse)
        for (complex& c: res)
            c /= 2;
    
    return res;
}

vector<complex> fft_droch(vector<complex>& a, int power, bool inverse)
{
    int n = 1 << power;
    
    if (n == 1)
        return a;
    
    vector<complex> res(n);
    {
        for (int i = 0; i < n; i++)
            res[rev(i, power)] = a[i];
        a = res;
    }
    
    /*vector<complex> even(n / 2), odd(n / 2);
    for (int i = 0; i < n / 2; i++)
    {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }
    
    vector<complex> fft_even = fft(even, power - 1, inverse);
    vector<complex> fft_odd  = fft(odd, power - 1, inverse);
    */
    //vector<complex> res(n);
    
    for (int P = 1; P <= power; P++)
    {
#if 0
        for (int i = 0; i < (1 << power); i++)
            printf("%f %f\n", a[i].real(), a[i].imag());
        printf("---\n");
#endif
        
        for (int block = 0; block < (1 << (power - P)); block++)
        {
            int base = block << P;
            int n = 1 << P;
            
            for (int i = 0; i < (1 << P) / 2; i++)
            {
                //double phi = 2 * pi * i / (double)(1 << power);
                //if (inverse) phi = -phi;
                
                //complex omega_i(cos(phi), sin(phi));
                
                int index = i << (ANGLES_POWER - P);
                if (inverse)
                {
                    index = ANGLES - index;
                    if (index == ANGLES) index = 0;
                }
                complex omega_i = w[index];
                
                res[base + i] = a[base + i] + omega_i * a[base + n / 2 + i];
                res[base + n / 2 + i] = a[base + i] - omega_i * a[base + n / 2 + i];
            }
        }
        
        a = res;
    }
    
    if (inverse)
        for (complex& c: a)
            c /= (1 << power);
    
    return a;
}

vector<complex> fft(vector<complex> a, int power, bool inverse)
{
    return fft_droch(a, power, inverse);
    
    vector<complex> x = fft_good(a, power, inverse);
    vector<complex> y = fft_droch(a, power, inverse);
    
    for (int i = 0; i < (1 << power); i++)
    {
        printf("%f %f  %f %f\n", x[i].real(), x[i].imag(), y[i].real(), y[i].imag());
    }
    
    for (int i = 0; i < (1 << power); i++)
    {
        assert(abs(x[i].real() - y[i].real()) < 1e-5);
        assert(abs(x[i].imag() - y[i].imag()) < 1e-5);
    }
    
    return y;
}

/*vector<complex> fft(vector<complex> a, bool inverse)
{
    // two extend
    
    int power = 0;
    while (power < 
}*/

const int maxN = 500500;
bool isNotPrime[maxN];
vector<int> primes;

void sieve()
{
    for (int i = 2; i < maxN; i++)
        if (!isNotPrime[i])
        {
            primes.push_back(i);
            if (i * (long long)i >= maxN) continue;
            for (int j = i * i; j < maxN; j += i)
                isNotPrime[j] = true;
        }
}

int main()
{
    sieve();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    bool read = true;
    
    int nt;
    if (read)
        cin >> nt;
    else
        nt = 1;
    
    for (int i = 0; i < ANGLES; i++)
        w[i] = complex(cos(2 * pi * i / ANGLES), sin(2 * pi * i / ANGLES));
        
    
    for (int i = 0; i < nt; i++)
    //while (true)
    {
        int n;
        string s;
        if (read)
            cin >> n >> s;
        else
        {
            n = rand() % 100 + 1;
            //n = 500000;
            //n = 100;
            s = string(n, '?');
            for (int i = 0; i < n; i++)
                s[i] = "VK?"[rand() % 3];
        }
        n = s.length();
        
        //printf("string: '%s'\n", s.c_str());
        
        int power = 0;
        while ((1 << power) < n) power++;
        
        // 2^power >= n;
        
        power++;
        vector<complex> a(1 << power), b(1 << power);
        for (int i = 0; i < n; i++)
            if (s[i] == 'V')
            {
                a[n - i] = complex(1, 0);
            }
            else if (s[i] == 'K')
            {
                b[i] = complex(1, 0);
            }
            
        a = fft(a, power, false);
        b = fft(b, power, false);
        for (int i = 0; i < (1 << power); i++)
            a[i] *= b[i];
        a = fft(a, power, true);
        
        //for (int i = 0; i < (1 << power); i++)
        //    printf("%.9f %.9f\n", a[i].real(), a[i].imag());
        
        vector<char> shift(n);
        
        for (int i = 0; i < n; i++)
        {
            if (abs(a[n + i].real()) > 1e-7)
            {
                shift[i] = true;
            }
            
            if (i != 0 && abs(a[i].real()) > 1e-7)
            {
                shift[n - i] = true;
            }
        }
            
#if 0
        vector<char> shift_exp(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (s[i] == 'V' && s[j] == 'K')
                    shift_exp[j - i] = true;
            
        for (int i = 0; i < n; i++)
            printf("shift %d: %d, expected: %d\n", i, shift[i], shift_exp[i]);
        
        assert(shift == shift_exp);
#endif

        //for (int t = 0; t < 5; t++) printf("%d ", primes[t]); printf("\n");
     
        for (int i = n - 1; i >= 2; i--)
            if (shift[i])
            {
                int j = i;
                vector<int> pdivs;
                //printf("%d is banned\n", i);
                for (int x: primes)
                {
                    //printf("test %d\n", x);
                    if (x * x > j) break;
                    if (j % x == 0)
                    {
                        pdivs.push_back(x);
                        //printf("ban %d too\n", i / x);
                        //break;
                        
                        while (j % x == 0) j /= x;
                    }
                }
                
                if (j != 1)
                    pdivs.push_back(j);
                
                for (int y: pdivs)
                    shift[i / y] = true;
            }
            
        vector<int> answer;
        
        shift[0] = true;
        for (int i = 0; i < n; i++)
            if (!shift[i])
                answer.push_back(i);
        answer.push_back(n);
            
        cout << answer.size() << '\n';
        for (int x: answer) cout << x << ' ';
        cout << '\n';
        
#if 0
        vector<int> answer_exp;
        for (int shift = 1; shift <= n; shift++)
        {
            vector<vector<char>> letters(shift);
            
            for (int i = 0; i < n; i++)
                if (s[i] != '?')
                    letters[i % shift].push_back(s[i]);
                
            bool fail = false;
            for (int i = 0; i < shift; i++)
            {
                sort(letters[i].begin(), letters[i].end());
                if (!letters[i].empty() && letters[i][0] != letters[i].back())
                {
                    fail = true;
                    break;
                }
            }
            
            //printf("shift %d: %d\n", shift, fail);
            
            if (!fail)
                answer_exp.push_back(shift);
        }
        
        cout.flush();
        printf("expected: ");
        for (int x: answer_exp) printf("%d ", x); printf("\n"); fflush(stdout);
        assert(answer == answer_exp);
#endif
    }
    
    return 0;
}