uses math;
Var a, b, c, n, k, m, d: int64;
Function sum(r: int64):int64;
Var q: longint;
    ans: int64;
Begin
    ans := (r + 1) * (r div 2);
    if r mod 2 = 1 then ans := ans + (r div 2) + 1;
    sum := ans;
End;
Begin
    Read(n, k);
    b := n mod k;
    a := k - b;
    c := n div k;
    d := sum(c-1);
    m := (a * d) + (b * sum(c));
    WriteLn(m, ' ', sum(n-k));
End.