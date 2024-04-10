Program arsijo;
Var n, k, i: longint;
        s: ansiString;
        ans, max: int64;
        c1, c2: char;
        ar: array ['A'..'Z'] of int64;
Begin
    ReadLn(n, k);
    ReadLn(s);
    for i:=1 to n do
        inc(ar[s[i]]);
    while k > 0 do
    begin
        max := ar['A'];
        c2 :='A';
        for c1 := 'B' to 'Z' do
                if max < ar[c1] then
                begin
                    max := ar[c1];
                    c2 := c1;
                end;
        ar[c2] := 0;
        dec(k, max);
        if k > 0 then
        begin
                ans := ans + sqr(max);
        end else
        begin
                ans := ans + sqr(k + max);
        end;
    end;
    WriteLn(ans);
End.