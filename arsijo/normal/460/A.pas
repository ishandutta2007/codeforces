Var n, i, a, m: longint;
    s: String;
Begin
    Readln(n, m);
    a := 0;
    while n > 0 do
    begin
        a := a + m;
        dec(n, m);
        if n < 0 then begin a := a + n; break; end;
        inc(n);
    end;
    WriteLn(a);
end.