Var l, r: int64;
Begin
    ReadLn(l, r);
    if l mod 2 = 1 then inc(l);
    if r - l >= 2 then WriteLn(l, ' ', l+1, ' ', l+2) else WriteLn(-1);
end.