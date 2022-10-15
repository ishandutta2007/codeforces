Program arsijo;
Var s: string;
        i: longint;
        b: boolean;
Begin
    ReadLn(s);
    //97 122 65 90
    if length(s) = 1 then
    begin
        if ( (ord(s[1]) >= 97) and (ord(s[1]) <= 122) ) then
                s[1] := chr ( ord ( s[1] ) - 32 ) else
        s[1] := chr ( ord ( s[1] ) + 32 );
    end else
    if  ( ord(s[2]) >= 65) and ( ord(s[2]) <= 90)  then
    begin
        b := true;
        for i:=3 to length(s) do
                if not ( ( ord ( s[i] ) >= 65 ) and
                        ( ord ( s[i] ) <= 90 ) ) then
                        begin
                            b := false;
                            break;
                        end;
        if b then
        begin
        if ( (ord(s[1]) >= 97) and (ord(s[1]) <= 122) ) then
                s[1] := chr ( ord ( s[1] ) - 32 ) else
                s[1] := chr ( ord ( s[1] ) + 32 );
        for i:=2 to length(s) do
                s[i] := chr ( ord ( s[i] ) + 32 );
        end;
       { for i:=1 to length(s) do
                if  ( ord(s[i]) >= 65) and ( ord(s[i]) <= 90) then
                        s[i] := chr ( ord ( s[i] ) + 32 ) else
                        s[i] := chr ( ord ( s[i] ) - 32 );  }
    end;
    WriteLn(s);
End.