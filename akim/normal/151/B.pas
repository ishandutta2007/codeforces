var a:array[1..100,1..3] of longint;
    s:array[1..100]of string;
    c:char;
    k,n,i,f,max1,max2,max3,tek,pred,k1,k2,k3:longint;
    log:boolean;
begin
 readln(n);max1:=0;max2:=0;max3:=0;
 for i:=1 to n do
 begin
  readln(k,c,s[i]);
  for f:=1 to k do
  begin
   read(c);
   case c of
   '0':tek:=0;
   '1':tek:=1;
   '2':tek:=2;
   '3':tek:=3;
   '4':tek:=4;
   '5':tek:=5;
   '6':tek:=6;
   '7':tek:=7;
   '8':tek:=8;
   '9':tek:=9;
   end;
   pred:=tek;
   read(c);
   case c of
   '0':tek:=0;
   '1':tek:=1;
   '2':tek:=2;
   '3':tek:=3;
   '4':tek:=4;
   '5':tek:=5;
   '6':tek:=6;
   '7':tek:=7;
   '8':tek:=8;
   '9':tek:=9;
   end;
   if tek= pred then log:=true else
   if tek< pred then log:=false else
   begin inc(a[i,1]);readln;continue;end;
   pred:=tek;
   read(c);
   read(c);
   case c of
   '0':tek:=0;
   '1':tek:=1;
   '2':tek:=2;
   '3':tek:=3;
   '4':tek:=4;
   '5':tek:=5;
   '6':tek:=6;
   '7':tek:=7;
   '8':tek:=8;
   '9':tek:=9;
   end;
   if log then if tek<>pred then begin inc(a[i,1]);readln;continue;end;
   if not(log) then if tek>=pred then begin inc(a[i,1]);readln;continue;end;
   pred:=tek;
   read(c);
   case c of
   '0':tek:=0;
   '1':tek:=1;
   '2':tek:=2;
   '3':tek:=3;
   '4':tek:=4;
   '5':tek:=5;
   '6':tek:=6;
   '7':tek:=7;
   '8':tek:=8;
   '9':tek:=9;
   end;
   if log then if tek<>pred then begin inc(a[i,1]);readln;continue;end;
   if not(log) then if tek>=pred then begin inc(a[i,1]);readln;continue;end;
   pred:=tek;
   read(c);
   read(c);
   case c of
   '0':tek:=0;
   '1':tek:=1;
   '2':tek:=2;
   '3':tek:=3;
   '4':tek:=4;
   '5':tek:=5;
   '6':tek:=6;
   '7':tek:=7;
   '8':tek:=8;
   '9':tek:=9;
   end;
   if log then if tek<>pred then begin inc(a[i,1]);readln;continue;end;
   if not(log) then if tek>=pred then begin inc(a[i,1]);readln;continue;end;
   pred:=tek;
   read(c);
   case c of
   '0':tek:=0;
   '1':tek:=1;
   '2':tek:=2;
   '3':tek:=3;
   '4':tek:=4;
   '5':tek:=5;
   '6':tek:=6;
   '7':tek:=7;
   '8':tek:=8;
   '9':tek:=9;
   end;
   if log then if tek<>pred then begin inc(a[i,1]);readln;continue;end;
   if not(log) then if tek>=pred then begin inc(a[i,1]);readln;continue;end;
   pred:=tek;
   readln;
   if log then inc(a[i,2]) else inc(a[i,3]);
  end;
  if max1=a[i,1] then begin max1:=a[i,1];k1:=k1+1;end;
  if max2=a[i,2] then begin max2:=a[i,2];k2:=k2+1;end;
  if max3=a[i,3] then begin max3:=a[i,3];k3:=k3+1;end;
  if max1<a[i,1] then begin max1:=a[i,1];k1:=1;end;
  if max2<a[i,2] then begin max2:=a[i,2];k2:=1;end;
  if max3<a[i,3] then begin max3:=a[i,3];k3:=1;end;
 end;
 write('If you want to call a taxi, you should call: ');
 for i:=1 to n do
  if a[i,2]=max2 then begin if k2=1 then writeln(s[i],'.') else begin write(s[i],', ');dec(k2);end;end;
 write('If you want to order a pizza, you should call: ');
 for i:=1 to n do
  if a[i,3]=max3 then begin if k3=1 then writeln(s[i],'.') else begin write(s[i],', ');dec(k3);end;end;
 write('If you want to go to a cafe with a wonderful girl, you should call: ');
 for i:=1 to n do
  if a[i,1]=max1 then begin if k1=1 then writeln(s[i],'.') else begin write(s[i],', ');dec(k1);end;end;
end.