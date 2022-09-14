var t,k,i,j,q,w:longint;
    f,tr:boolean;
    c:array[1..12] of char;
    u:array[1..12] of longint;
    a:array[1..12,1..12] of char;
begin
 readln (t);
 for i:=1 to t do
        begin
         for j:=1 to 12 do read (c[j]);
         readln;
         k:=0;
         for w:=1 to 12 do
                begin

                 if 12 mod w=0 then
                        begin
                         f:=false;
                         for j:=1 to w do
                                for q:=1 to 12 div w do
                                        begin
                                         a[j,q]:=c[(j-1)*(12 div w)+q];
                                        end;
                         for j:=1 to 12 div w do
                                begin
                                 tr:=true;
                                 for q:=1 to w do
                                        if a[q,j]='O' then tr:=false;

                                 if tr then f:=true;

                                end;
                         if f then
                               begin
                                inc (k);
                                u[k]:=w;
                               end;

                        end;
                end;
         write (k,' ');
         for j:=1 to k do write (u[j],'x',12 div u[j],' ');
         writeln;
        end;
end.