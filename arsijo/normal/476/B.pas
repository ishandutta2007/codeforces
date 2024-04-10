Var p1, p2, m1, m2, a, r, i, j, n, m: longint;
    s1, s2: String;
Procedure c(b, q, res, last: longint);
Begin
    //WriteLn(b, ' ',q);
    if (q = last) then
    begin
        if (b+n = res) then inc(r);
        exit;
    end;
    c(b-1, q+1, res, last);
    c(b+1, q+1, res, last);
End;
Begin
    ReadLn(s1);
    ReadLN(s2);
    r := 0;
    p1 := 0; p2 := 0; m1 := 0; m2 := 0; a := 0;
    for i:=1 to length(s1) do if s1[i] = '+' then inc(p1) else inc(m1);
    for i:=1 to length(s2) do if s2[i] = '+' then inc(p2) else if s2[i] = '-' then inc(m2) else inc(a);
    //WriteLn(p1, ' ', m1, ' ', p2, ' ', m2, ' ', a);
    if a = 0 then
    begin
        if (m1 = m2) and (p1 = p2) then WriteLn(1.000000000) else WriteLn(0.000000000);
        exit;
    end;
    n := (p2 - m2);
    c(0, 0, (p1 - m1) , a);
    m := 1;
    for i:=1 to a do m := m * 2;
    WriteLn(r/m:0:9);
End.