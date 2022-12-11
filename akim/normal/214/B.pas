var a:array[0..9]of longint;
    n,i,k,s:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(k);
  inc(a[k]);
  s:=s+k;
 end;
 if a[0]=0 then begin writeln(-1);halt(0);end;
 if s mod 3=1 then
 begin
  if a[1]>0 then begin dec(a[1]);s:=s-1;end else
  if a[4]>0 then begin dec(a[4]);s:=s-4;end else
  if a[7]>0 then begin dec(a[7]);s:=s-7;end else
  if (a[2]>1)and(a[2]>1) then begin dec(a[2]);dec(a[2]);s:=s-4;end else
  if (a[2]>0)and(a[5]>0) then begin dec(a[2]);dec(a[5]);s:=s-7;end else
  if (a[5]>1)and(a[5]>1) then begin dec(a[5]);dec(a[5]);s:=s-10;end else
  if (a[2]>0)and(a[8]>0) then begin dec(a[2]);dec(a[8]);s:=s-10;end else
  if (a[5]>0)and(a[8]>0) then begin dec(a[5]);dec(a[8]);s:=s-13;end else
  if (a[8]>1)and(a[8]>1) then begin dec(a[8]);dec(a[8]);s:=s-16;end else
  begin writeln(0);halt(0);end;
 end;
 if s mod 3=2 then
 begin
  if a[2]>0 then begin dec(a[2]);s:=s-2;end else
  if a[5]>0 then begin dec(a[5]);s:=s-5;end else
  if a[8]>0 then begin dec(a[8]);s:=s-8;end else
  if (a[1]>1)and(a[1]>1) then begin dec(a[1]);dec(a[1]);s:=s-2;end else
  if (a[1]>0)and(a[4]>0) then begin dec(a[1]);dec(a[4]);s:=s-5;end else
  if (a[4]>1)and(a[4]>1) then begin dec(a[4]);dec(a[4]);s:=s-8;end else
  if (a[1]>0)and(a[7]>0) then begin dec(a[1]);dec(a[7]);s:=s-8;end else
  if (a[4]>0)and(a[7]>0) then begin dec(a[4]);dec(a[7]);s:=s-11;end else
  if (a[7]>1)and(a[7]>1) then begin dec(a[7]);dec(a[7]);s:=s-14;end else
  begin writeln(0);halt(0);end;
 end;
 if s=0 then begin writeln('0');halt(0);end;
 for i:=1 to a[9] do
  write('9');
 for i:=1 to a[8] do
  write('8');
 for i:=1 to a[7] do
  write('7');
 for i:=1 to a[6] do
  write('6');
 for i:=1 to a[5] do
  write('5');
 for i:=1 to a[4] do
  write('4');
 for i:=1 to a[3] do
  write('3');
 for i:=1 to a[2] do
  write('2');
 for i:=1 to a[1] do
  write('1');
 for i:=1 to a[0] do
  write('0');
end.