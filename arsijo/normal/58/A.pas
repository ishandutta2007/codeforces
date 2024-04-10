Const st: String = 'hello';
Var n, i, a, m: longint;
    s: String;
Begin
    m := 1;
    ReadLn(s);
    for i:=1 to length (s) do
    begin
        if s[i] = st[m] then inc(m);
        if m > 5 then break;
    end;
    if m > 5 then WriteLn('YES') ELSE WriteLn('NO');
end.