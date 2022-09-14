var n,m,i:longint;
    s:ansistring;
begin
 read (n,m);
         if n-1=m then
                begin
                 for i:=1 to m do s:=s+'01';
                 s:=s+'0';
                end;
         if m=2*n+1 then
                begin
                 for i:=1 to n do s:=s+'110';
                 s:=s+'1';
                end;
         if m=2*n+2 then
                begin
                 for i:=1 to n do s:=s+'110';
                 s:=s+'11';
                end;
         if (n<=m) and (m<=2*n) then
                begin
                 for i:=1 to n do
                        begin
                         if i<=m-n then s:=s+'110'
                                   else s:=s+'10';

                        end;
                end;

         if not ((n-1<=m) and (m<=2*n+2)) then s:='-1';
         write (s);
end.