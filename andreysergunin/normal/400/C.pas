
var n,m,x,y,z,p,xx,yy,x0,y0,t,n0,m0:int64;
    i,j:longint;
begin
 read (n,m,x,y,z,p);
 n0:=n;
 m0:=m;
 for i:=1 to p do
        begin
         m:=m0;
         n:=n0;
         read (x0,y0);
         for j:=1 to x mod 4 do
                begin
                 xx:=x0;
                 yy:=y0;
                 y0:=n-xx+1;
                 x0:=yy;
                 t:=n;
                 n:=m;
                 m:=t;
                end;
         if y mod 2=1 then
                y0:=m-y0+1;
         for j:=1 to z mod 4 do
                begin
                 xx:=x0;
                 yy:=y0;
                 y0:=xx;
                 x0:=m-yy+1;
                 t:=n;
                 n:=m;
                 m:=t;
                end;
         writeln (x0,' ',y0);
        end;
end.