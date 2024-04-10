var pos, n,m,k,i,d,s,sumb,suma:longint;
b,a:array[1..1000000] of longint;
procedure bs(l,r:int64);
var d,s:longint;
c:extended;
   begin
   while r-l>1 do
       begin
       s:=0;
       d:=(l+r) div 2;
       c:=1.0 ;
       if c*sumb*d>c*suma+c*k then
                 s:=maxlongint else
                 begin
       for i:=1 to n do
          if b[i]*d>a[i] then s:=s+b[i]*d-a[i];
          end;
       if s>k then r:=d else l:=d;
       end;



   pos:=l;
   end;
   begin
   read(n,k);
   for i:=1 to n do read(b[i]);
   for i:=1 to n do read(a[i]);
   for i:=1 to n do
   begin
   sumb:=sumb+b[i];
   suma:=suma+a[i];
   end;
   bs(0,10000000);
   pos:=pos+1;
   d:=pos;
     for i:=1 to n do
          if b[i]*d>a[i] then begin s:=s+b[i]*d-a[i]; {writeln(s);} end;
     if s>k then dec(pos);
   d:=pos;
    s:=0;
//   writeln;
     for i:=1 to n do
          if b[i]*d>a[i] then  begin s:=s+b[i]*d-a[i]; end;

     if s>k then dec(pos);
     writeln(pos);

   end.