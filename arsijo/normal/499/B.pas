Program arsijo;
Var n, m, i, j, pos: longint;
        st: ansiString;
        s1, s2: array [1..3000] of ansiString;
Procedure change(s: ansiString; g: longint);
Var q: longint;
Begin
        for q := 1 to length(s) do
                if s[q] = ' ' then
                begin
                        s1[g] := copy(s, 1, q-1);
                        s2[g] := copy(s, q+1, length(s) - q);
                        exit;
                end;
End;
Function getSomething(s: ansiString): ansiString;
Var j: longint;
Begin
        for j:=1 to m do
                if (s1[j] = s) or (s2[j] = s) then
                begin
                        if length(s1[j]) <= length(s2[j]) then
                                exit(s1[j]) else exit(s2[j]);
                end;
End;
Begin
        ReadLn(n, m);
        for i:=1 to m do
        begin
            ReadLn(st);
            change(st, i);
            //WriteLn(s1[i], ' ', s2[i]);
        end;
        ReadLn(st);
        pos := 1;
        for i:=2 to length(st) do
                if st[i] = ' ' then
                begin
                        //Write(copy(st, pos, i - pos + 1));
                        Write(getSomething(copy(st, pos, i - pos)), ' ');
                        pos := i + 1;
                        //WriteLn('pos = ', pos);
                end;
        if st[length(st)] <> ' ' then
        begin
               // write('+');
            Write(getSomething(copy(st, pos, length(st) - pos + 1)));
        end;
End.