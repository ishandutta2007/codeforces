Program arsijo;
Var s1, s2: String;
        n, i, a, b, e, f: longint;
        c, d: char;
        ar1, ar2: array [1..2, 1..99] of boolean;
Begin
        {Assign(input, 'input.txt');
        reset(input);}
        ReadLn(s1);
        ReadLn(s2);
        ReadLn(n);
        for i:=1 to n do
        begin
            Read(a);
            Read(c);
            Read(c);
            Read(b);
            Read(d);
            Read(d);
            if (c = 'h') then
                e := 1 else
                e := 2;
            if ar1[e, b] then continue;
            if (d = 'y') then
            begin
                if ar2[e, b] then
                        d := 'r' else
                        ar2[e, b] := true;

            end;

                if (d = 'r') then
                begin
                        if (e = 1) then Write(s1, ' ') else
                        Write(s2, ' ');
                WriteLn(b, ' ', a);
                ar1[e, b] := true;
                end;
        end;
End.