Program arsijo;
Var s: ansiString;
        i: longint;
Begin
        //97 122 65 90
    ReadLn(s);
    if ( ord ( s[1] ) >= 97 ) and ( ord ( s[1] ) <= 122 ) then
        s[1] := chr ( ord ( s[1] ) - 32 );
    WriteLn(s);
End.