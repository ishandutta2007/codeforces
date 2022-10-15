Var n, i, a: longint;
    s: String;
Begin
    Readln(n);
    Readln(s);
    a := 1;
    for i:=1 to length(s) do
    begin
        if s[i] = '1' then inc(a) else break;
    end;
    if a > n then dec(a);
    WriteLn(a);
end.