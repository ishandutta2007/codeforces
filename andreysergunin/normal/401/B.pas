var x,k,b,c,s,ma,mi,i,a:longint;
    u:array[0..5000] of byte;
begin
 read (x,k);
 for i:=1 to k do
        begin
         read (a);
         if a=1 then
                begin
                 read (b,c);
                 u[b]:=2;
                 u[c]:=1;
                end
                else
                begin
                 read (b);
                 u[b]:=2;
                end;
        end;
 s:=0;
 u[0]:=-1;
 for i:=x-1 downto 0 do
        begin
         if u[i]=0 then
                begin
                 inc (ma);
                 inc (s);
                end
                else
                begin
                 mi:=mi+(s+1) div 2;
                 s:=0
                end;
        end;
 write (mi,' ',ma);

end.