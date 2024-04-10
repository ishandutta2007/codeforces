Program arsijo;
Var i, n, min, a, b, h, m, lh, lm: longint;
Begin
        Read(n);
        Read(lh, lm);
        min := 0;
        a := 0;
        for i:=2 to n do
        begin
                Read(h, m);
                //WriteLn('. ', h,' ',m,' ', lh,' ', lm);
                if (h = lh) and (m = lm) then
                begin
                    inc(a);
                end else
                begin
                    if a > min then
                        min := a;
                    a := 0;
                end;
                lh := h;
                lm := m;
        end;
        if a > min then
                min := a;
        WriteLn(min+1);
End.