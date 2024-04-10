Program arsijo;
Var a, b, c, i, n: longint;
        ans: int64;
Begin
        Read(n);
        for i:=1 to n do
        begin
            Read(a);
            inc(ans, a);
        end;
        if ans mod n = 0 then
                WriteLn(n) else
                WriteLn(n-1);
End.