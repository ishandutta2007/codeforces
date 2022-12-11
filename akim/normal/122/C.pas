var a:array[0..2049]of int64;
    f:longint;i,l,r,s,z:int64;
begin
 a[0]:=0;
 for f:=1 to 2047 do if f mod 2=1 then a[f]:=4 else a[f]:=7;
 z:=10;for f:=3 to 2047 do if (f-1) div 2 mod 2=1 then a[f]:=a[f]+4*z else a[f]:=a[f]+7*z;
 z:=z*10;for f:=7 to 2047 do if (f-3) div 4 mod 2=1 then a[f]:=a[f]+4*z else a[f]:=a[f]+7*z;
 z:=z*10;for f:=15 to 2047 do if (f-7) div 8 mod 2=1 then a[f]:=a[f]+4*z else a[f]:=a[f]+7*z;
 z:=z*10;for f:=31 to 2047 do if (f-15) div 16 mod 2=1 then a[f]:=a[f]+4*z else a[f]:=a[f]+7*z;
 z:=z*10;for f:=63 to 2047 do if (f-31) div 32 mod 2=1 then a[f]:=a[f]+4*z else a[f]:=a[f]+7*z;
 z:=z*10;for f:=127 to 2047 do if (f-63) div 64 mod 2=1 then a[f]:=a[f]+4*z else a[f]:=a[f]+7*z;
 z:=z*10;for f:=255 to 2047 do if (f-127) div 128 mod 2=1 then a[f]:=a[f]+4*z else a[f]:=a[f]+7*z;
 z:=z*10;for f:=511 to 2047 do if (f-255) div 256 mod 2=1 then a[f]:=a[f]+4*z else a[f]:=a[f]+7*z;
 z:=z*10;for f:=1023 to 2047 do if (f-511) div 512 mod 2=1 then a[f]:=a[f]+4*z else a[f]:=a[f]+7*z;
 readln(l,r);
 i:=0;s:=0;
 while a[i]<=r do
 begin
  while a[i]<l do inc(i);
  s:=s+a[i]*(a[i]-l+1);
  l:=a[i]+1;
 end;
 s:=s-(a[i]-r)*a[i];
 writeln(s);
end.