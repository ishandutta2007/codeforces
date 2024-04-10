Var n, m: longint;
    s1, s2: String;
Begin
    ReadLn(n, m);
    ReadLn(s1);
    ReadLn(s2);
    if ( (s1[1] = '>') and (s1[n] = '<') and (s2[1] = '^') and (s2[m] = 'v') ) or (
         (s1[1] = '<') and (s1[n] = '>') and (s2[1] = 'v') and (s2[m] = '^') ) then WriteLn('YES') else WriteLn('NO');

End.