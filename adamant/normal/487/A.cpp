#include <bits/stdc++.h>

using namespace std;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int am,bm,cm;
    cin >> am >> bm >> cm;
    int ah,bh,ch;
    cin >> ah >> bh >> ch;
    int ac,bc,cc;
    cin >> ac >> bc >> cc;
    int ans = 1000000000;
        for(int k = 0; k <= 100000; k++)
        {
            int i = 0, j = 0;
                am += i; bm += j; cm += k;
                if(bm <= ch)
                {
                am -= i; bm -= j; cm -= k;
                continue;
                }
                if(bh <= cm)
                {
                ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
                continue;
                }

                if(ah / (max(0, bm - ch)) + bool(ah % (max(0, bm - ch))) < am / (max(0, bh - cm)) + bool(am % (max(0, bh - cm))))
                    ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
        }
        for(int j = 0; j <= 100000; j++)
        {
            int i = 0, k = 0;
                am += i; bm += j; cm += k;
                if(bm <= ch)
                {
                am -= i; bm -= j; cm -= k;
                continue;
                }
                if(bh <= cm)
                {
                ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
                continue;
                }

                if(ah / (max(0, bm - ch)) + bool(ah % (max(0, bm - ch))) < am / (max(0, bh - cm)) + bool(am % (max(0, bh - cm))))
                    ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
        }
        for(int i = 0; i <= 100000; i++)
        {
            int j = 0, k = 0;
                am += i; bm += j; cm += k;
                if(bm <= ch)
                {
                am -= i; bm -= j; cm -= k;
                continue;
                }
                if(bh <= cm)
                {
                ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
                continue;
                }

                if(ah / (max(0, bm - ch)) + bool(ah % (max(0, bm - ch))) < am / (max(0, bh - cm)) + bool(am % (max(0, bh - cm))))
                    ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
        }
    for(int k = 0; k <= 7000; k++)
        for(int i = 0; i <= 7000; i++)
        {
            int j = 0;
                am += i; bm += j; cm += k;
                if(bm <= ch)
                {
                am -= i; bm -= j; cm -= k;
                continue;
                }
                if(bh <= cm)
                {
                ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
                continue;
                }

                if(ah / (max(0, bm - ch)) + bool(ah % (max(0, bm - ch))) < am / (max(0, bh - cm)) + bool(am % (max(0, bh - cm))))
                    ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
        }
    for(int k = 0; k <= 7000; k++)
        for(int j = 0; j <= 7000; j++)
        {
            int i = 0;
                am += i; bm += j; cm += k;
                if(bm <= ch)
                {
                am -= i; bm -= j; cm -= k;
                continue;
                }
                if(bh <= cm)
                {
                ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
                continue;
                }

                if(ah / (max(0, bm - ch)) + bool(ah % (max(0, bm - ch))) < am / (max(0, bh - cm)) + bool(am % (max(0, bh - cm))))
                    ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
        }
    for(int i = 0; i <= 7000; i++)
        for(int j = 0; j <= 7000; j++)
        {
            int k = 0;
                am += i; bm += j; cm += k;
                if(bm <= ch)
                {
                am -= i; bm -= j; cm -= k;
                continue;
                }
                if(bh <= cm)
                {
                ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
                continue;
                }

                if(ah / (max(0, bm - ch)) + bool(ah % (max(0, bm - ch))) < am / (max(0, bh - cm)) + bool(am % (max(0, bh - cm))))
                    ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
        }
    for(int i = 0; i <= 350; i++)
        for(int j = 0; j <= 350; j++)
            for(int k = 0; k <= 350; k++)
            {
                am += i; bm += j; cm += k;
                if(bm <= ch)
                {
                am -= i; bm -= j; cm -= k;
                continue;
                }
                if(bh <= cm)
                {
                ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
                continue;
                }

                if(ah / (max(0, bm - ch)) + bool(ah % (max(0, bm - ch))) < am / (max(0, bh - cm)) + bool(am % (max(0, bh - cm))))
                    ans = min(ans, i*ac + j*bc + k*cc);
                am -= i; bm -= j; cm -= k;
            }
    cout << ans << "\n";
    return 0;
}