Program arsijo;
uses math;
var n, m, i, j, a, c, len, l, r, mi, q, w, e: longint;
    s: ansistring;
Function getDifference(c1, c2: char): longint;
Var q, w, e: longint;
Begin
    q := abs(ord(c1) - ord(c2));
    w := abs(122 - ord(c1)) + abs(97 - ord(c2)) + 1;
    e := abs(122 - ord(c2)) + abs(97 - ord(c1)) + 1;
    getDifference := min(min(q, w), e);
End;
Begin
    ReadLn(n, m);
    Readln(s);
    mi := 0;
    len := 0;
    if m > ( (n div 2) + (n mod 2) ) then m := m - (2 * (m - (n div 2))) + 1 +(n mod 2);
    for i:=1 to (n div 2) do
    begin
        a := getDifference(s[i], s[n-i+1]);
        if a <> 0 then
        begin
            inc(len);
            inc(mi, a);
            if len = 1 then l := i;
            r := i;
        end;
    end;
    if len = 0 then begin WriteLn(0); exit; end;
    if r < m then w := m - l else if l > m then w := r - m else
    begin
        l := abs(m - l);
        r := abs(r - m);
        if r = l then w := r else if l > r then w := (r * 2 + l) else w := (l * 2 + r);
    end;
    WriteLn(mi + w);

End.